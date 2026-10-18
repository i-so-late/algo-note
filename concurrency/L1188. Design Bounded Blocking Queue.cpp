// LeetCode 1188. Design Bounded Blocking Queue (Premium), local practice version
// Build and run: g++ -std=c++20 -O2 -pthread -I . "concurrency/L1188. Design Bounded Blocking Queue.cpp" -o bbq && ./bbq
//
// Problem:
//   Implement a thread-safe queue with a fixed capacity.
//   - BoundedBlockingQueue(int capacity): constructor; capacity is the maximum number of elements
//   - void enqueue(int element): add element to the back; if the queue is full, block until there is space
//   - int dequeue(): remove and return the front element; if the queue is empty, block until there is an element
//   - int size(): return the number of elements currently in the queue
//   Several producer threads call enqueue and several consumer threads call dequeue, all at the same time.

#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include "data_structures/structures.hpp"

// ==================== Your implementation goes here ====================
class BoundedBlockingQueue {
    mutex m;
    condition_variable cv_en;
    condition_variable cv_de;
    int cap;
    queue<int> que;
public:
    BoundedBlockingQueue(int capacity) : cap(capacity) {}

    void enqueue(int element) {
        unique_lock<mutex> lk(m);
        cv_en.wait(lk, [this]{ return que.size()<cap; });
        que.push(element);
        lk.unlock();
        cv_de.notify_one();
    }

    int dequeue() {
        unique_lock<mutex> lk(m);
        cv_de.wait(lk, [this]{ return !que.empty(); });
        int tmp = que.front();
        que.pop();
        lk.unlock();
        cv_en.notify_one();
        return tmp;
    }

    int size() {
        lock_guard<mutex> lk(m);
        return que.size();
    }
};
// ==================== End of implementation ====================


// -------------------- Tests below, no need to change --------------------
static int failures = 0;

static void check(bool ok, const char* what) {
    printf("  [%s] %s\n", ok ? "PASS" : "FAIL", what);
    if (!ok) ++failures;
}

// Timeout watchdog: running too long means some thread is blocked forever (deadlock or a missed notify)
static void startWatchdog(int seconds) {
    thread([seconds] {
        this_thread::sleep_for(chrono::seconds(seconds));
        printf("\nTIMEOUT: did not finish within %d seconds, a thread may be blocked forever (deadlock / missed notify)\n", seconds);
        fflush(stdout);
        _Exit(1);
    }).detach();
}

// Test 1: single producer and single consumer, check FIFO order
static void testFifo() {
    printf("Test 1: single producer + single consumer, FIFO order\n");
    const int cap = 3, n = 1000;
    BoundedBlockingQueue q(cap);
    vector<int> got;
    thread consumer([&] {
        for (int i = 0; i < n; ++i) got.push_back(q.dequeue());
    });
    thread producer([&] {
        for (int i = 0; i < n; ++i) q.enqueue(i);
    });
    producer.join();
    consumer.join();
    bool inOrder = (int)got.size() == n;
    for (int i = 0; inOrder && i < n; ++i) inOrder = (got[i] == i);
    check(inOrder, "elements come out in the order they went in");
    check(q.size() == 0, "size() == 0 at the end");
}

// Test 2: dequeue must block on an empty queue
static void testBlockOnEmpty() {
    printf("Test 2: dequeue should block on an empty queue\n");
    BoundedBlockingQueue q(2);
    atomic<bool> done{false};
    int value = -1;
    thread consumer([&] {
        value = q.dequeue();
        done = true;
    });
    this_thread::sleep_for(chrono::milliseconds(100));
    check(!done, "dequeue did not return early while the queue was empty");
    q.enqueue(42);
    consumer.join();
    check(value == 42, "after an element was added, the blocked dequeue received it");
}

// Test 3: enqueue must block on a full queue
static void testBlockOnFull() {
    printf("Test 3: enqueue should block on a full queue\n");
    BoundedBlockingQueue q(2);
    q.enqueue(1);
    q.enqueue(2);
    atomic<bool> done{false};
    thread producer([&] {
        q.enqueue(3);
        done = true;
    });
    this_thread::sleep_for(chrono::milliseconds(100));
    check(!done, "enqueue did not return early while the queue was full");
    check(q.size() == 2, "size() == 2 while the queue is full");
    int a = q.dequeue();
    producer.join();
    int b = q.dequeue();
    int c = q.dequeue();
    check(a == 1 && b == 2 && c == 3, "1, 2, 3 come out in order");
}

// Test 4: stress test with multiple producers and multiple consumers
static void testStress(int producers, int consumers, bool checkPerProducerOrder) {
    printf("Test 4: %d producers + %d consumers, stress test\n", producers, consumers);
    const int cap = 5, perProducer = 20000;
    const int total = producers * perProducer;
    BoundedBlockingQueue q(cap);

    atomic<bool> running{true};
    atomic<bool> sizeOk{true};
    thread monitor([&] {
        while (running) {
            int s = q.size();
            if (s < 0 || s > cap) sizeOk = false;
            this_thread::yield();
        }
    });

    vector<vector<int>> got(consumers);
    vector<thread> ts;
    for (int c = 0; c < consumers; ++c) {
        int quota = total / consumers + (c < total % consumers ? 1 : 0);
        ts.emplace_back([&, c, quota] {
            for (int i = 0; i < quota; ++i) got[c].push_back(q.dequeue());
        });
    }
    for (int p = 0; p < producers; ++p) {
        ts.emplace_back([&, p] {
            for (int i = 0; i < perProducer; ++i) q.enqueue(p * perProducer + i);
        });
    }
    for (auto& t : ts) t.join();
    running = false;
    monitor.join();

    vector<int> all;
    for (auto& v : got) all.insert(all.end(), v.begin(), v.end());
    vector<int> sorted = all;
    sort(sorted.begin(), sorted.end());
    bool complete = (int)sorted.size() == total;
    for (int i = 0; complete && i < total; ++i) complete = (sorted[i] == i);

    check(complete, "every element is taken out exactly once (none lost, none duplicated)");
    check(sizeOk, "size() stays within [0, capacity] for the whole run");
    check(q.size() == 0, "size() == 0 at the end");

    if (checkPerProducerOrder) {
        vector<int> last(producers, -1);
        bool ordered = true;
        for (int x : all) {
            int p = x / perProducer;
            if (x <= last[p]) { ordered = false; break; }
            last[p] = x;
        }
        check(ordered, "elements from the same producer come out in their original order");
    }
}

int main() {
    startWatchdog(10);
    testFifo();
    testBlockOnEmpty();
    testBlockOnFull();
    testStress(4, 1, true);
    testStress(4, 4, false);
    testStress(1, 4, false);
    printf("\n%s\n", failures == 0 ? "ALL PASSED" : "SOME TESTS FAILED");
    return failures == 0 ? 0 : 1;
}
