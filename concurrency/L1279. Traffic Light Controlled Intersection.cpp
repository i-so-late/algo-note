// LeetCode 1279. Traffic Light Controlled Intersection (Premium), local practice version
// Build and run: g++ -std=c++20 -O2 -pthread -I . "concurrency/L1279. Traffic Light Controlled Intersection.cpp" -o traffic && ./traffic
//
// Problem:
//   An intersection where two roads cross:
//   - Road A (roadId = 1): direction 1 is north to south, direction 2 is south to north
//   - Road B (roadId = 2): direction 3 is west to east, direction 4 is east to west
//   Each road has a traffic light at the intersection. Only one road can be green at a time, and cars on the green road may pass in both directions.
//   Initial state: Road A is green, Road B is red.
//
//   Each car is a thread and calls carArrived() once when it reaches the intersection:
//   - carId: the car's ID
//   - roadId: the road the car is on, 1 = A, 2 = B
//   - direction: the car's direction, 1 to 4
//   - turnGreen(): call it to turn "the road this car is on" green (the other road turns red)
//   - crossCar(): call it to let this car pass through the intersection
//
//   Requirements:
//   - Cars on the two roads must not be in the intersection at the same time
//   - Calling turnGreen() on a road that is already green counts as wrong
//   - No deadlock: every car must eventually pass
//   Several output orders are valid; any order that meets the conditions above is correct.

#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <random>
#include "data_structures/structures.hpp"

// ==================== Your implementation goes here ====================
class TrafficLight {
    mutex m;
    int isGreen;
public:
    TrafficLight() {
        isGreen = 1;
    }

    void carArrived(
        int carId,                   // the car's ID
        int roadId,                  // the road the car is on: 1 = Road A, 2 = Road B
        int direction,               // the car's direction
        function<void()> turnGreen,  // call it to turn the current road green
        function<void()> crossCar    // call it to let this car pass through the intersection
    ) {
        lock_guard<mutex> lk(m);
        if(isGreen == roadId){
            crossCar();
        }else{
            isGreen = roadId;
            turnGreen();
            crossCar();
        }
        return;
    }
};
// ==================== End of implementation ====================


// -------------------- Tests below, no need to change --------------------
namespace tst {

int failures = 0;

void check(bool ok, const string& what) {
    printf("  [%s] %s\n", ok ? "PASS" : "FAIL", what.c_str());
    if (!ok) ++failures;
}

void startWatchdog(int seconds) {
    thread([seconds] {
        this_thread::sleep_for(chrono::seconds(seconds));
        printf("\nTIMEOUT: did not finish within %d seconds, a car may be waiting at the intersection forever (deadlock / missed notify)\n", seconds);
        fflush(stdout);
        _Exit(1);
    }).detach();
}

struct Car {
    int id;
    int direction;
    int arrivalMs;
};

// Simulated judge: records events and checks for rule violations
struct Judge {
    mutex m;
    int green = 1;
    int crossing[3] = {0, 0, 0};
    vector<string> log;
    unordered_map<int, int> crossedTimes;
    int crossMs = 0;
    bool doubleGreen = false;       // turnGreen called on a road that is already green
    bool crossOnRed = false;        // a car passed on red
    bool mixedRoads = false;        // cars from both roads in the intersection at the same time
    bool switchWhileBusy = false;   // the light switched while cars were still in the intersection

    void turnGreen(int road) {
        lock_guard<mutex> lk(m);
        if (green == road) doubleGreen = true;
        if (crossing[1] + crossing[2] > 0) switchWhileBusy = true;
        green = road;
        log.push_back(string("Traffic Light On Road ") + (road == 1 ? "A" : "B") + " Is Green");
    }

    void crossCar(int id, int road, int direction) {
        {
            lock_guard<mutex> lk(m);
            if (green != road) crossOnRed = true;
            ++crossing[road];
            if (crossing[3 - road] > 0) mixedRoads = true;
            ++crossedTimes[id];
            log.push_back("Car " + to_string(id) + " Has Passed Road " + (road == 1 ? "A" : "B") +
                          " In Direction " + to_string(direction));
        }
        if (crossMs > 0) this_thread::sleep_for(chrono::milliseconds(crossMs));   // simulates the time it takes to pass through the intersection
        {
            lock_guard<mutex> lk(m);
            --crossing[road];
        }
    }
};

struct Result {
    bool allCrossedOnce = true;
    bool doubleGreen = false, crossOnRed = false, mixedRoads = false, switchWhileBusy = false;
    vector<string> log;
};

Result runOnce(const vector<Car>& cars, int crossMs) {
    Judge judge;
    judge.crossMs = crossMs;
    TrafficLight light;

    atomic<bool> go{false};
    chrono::steady_clock::time_point start;
    vector<thread> ts;
    for (const Car& c : cars) {
        ts.emplace_back([&, c] {
            while (!go) this_thread::yield();
            this_thread::sleep_until(start + chrono::milliseconds(c.arrivalMs));
            int road = c.direction <= 2 ? 1 : 2;
            light.carArrived(c.id, road, c.direction,
                             [&judge, road] { judge.turnGreen(road); },
                             [&judge, c, road] { judge.crossCar(c.id, road, c.direction); });
        });
    }
    start = chrono::steady_clock::now() + chrono::milliseconds(5);
    go = true;
    for (auto& t : ts) t.join();

    Result r;
    for (const Car& c : cars) {
        auto it = judge.crossedTimes.find(c.id);
        if (it == judge.crossedTimes.end() || it->second != 1) r.allCrossedOnce = false;
    }
    r.doubleGreen = judge.doubleGreen;
    r.crossOnRed = judge.crossOnRed;
    r.mixedRoads = judge.mixedRoads;
    r.switchWhileBusy = judge.switchWhileBusy;
    r.log = judge.log;
    return r;
}

void report(const Result& r) {
    check(r.allCrossedOnce, "every car passes exactly once");
    check(!r.doubleGreen, "turnGreen never called on a road that is already green");
    check(!r.crossOnRed, "no car passed on red");
    check(!r.mixedRoads, "cars from the two roads were never in the intersection at the same time");
    check(!r.switchWhileBusy, "the light never switched while cars were in the intersection");
}

vector<Car> makeCars(const vector<int>& ids, const vector<int>& dirs, const vector<int>& times) {
    vector<Car> cars;
    for (size_t i = 0; i < ids.size(); ++i) cars.push_back({ids[i], dirs[i], times[i]});
    return cars;
}

void caseExample(const string& name, const vector<Car>& cars) {
    printf("%s\n", name.c_str());
    Result r = runOnce(cars, 0);
    printf("     your output:\n");
    for (const string& line : r.log) printf("       %s\n", line.c_str());
    report(r);
}

// Many cars on both roads arrive almost at once, repeated over many rounds to expose concurrency bugs
void caseStress() {
    printf("Test 4: stress test, 20 cars arrive almost at once, repeated for 100 rounds\n");
    mt19937 rng(7);
    uniform_int_distribution<int> dir(1, 4), arrive(0, 3);
    Result agg;
    for (int round = 0; round < 100; ++round) {
        vector<Car> cars;
        for (int i = 1; i <= 20; ++i) cars.push_back({i, dir(rng), arrive(rng)});
        Result r = runOnce(cars, 1);
        agg.allCrossedOnce = agg.allCrossedOnce && r.allCrossedOnce;
        agg.doubleGreen = agg.doubleGreen || r.doubleGreen;
        agg.crossOnRed = agg.crossOnRed || r.crossOnRed;
        agg.mixedRoads = agg.mixedRoads || r.mixedRoads;
        agg.switchWhileBusy = agg.switchWhileBusy || r.switchWhileBusy;
    }
    report(agg);
}

// All cars on Road A: A is green from the start, so turnGreen should never be called
void caseAllRoadA() {
    printf("Test 5: 20 cars all on Road A, arriving at the same time\n");
    vector<Car> cars;
    for (int i = 1; i <= 20; ++i) cars.push_back({i, i % 2 == 0 ? 1 : 2, 0});
    report(runOnce(cars, 1));
}

}  // namespace tst

int main() {
    tst::startWatchdog(60);
    tst::caseExample("Test 1: problem example 1",
                     tst::makeCars({1, 3, 5, 2, 4}, {2, 1, 2, 4, 3}, {10, 20, 30, 40, 50}));
    tst::caseExample("Test 2: problem example 2",
                     tst::makeCars({1, 2, 3, 4, 5}, {2, 4, 3, 3, 1}, {10, 20, 30, 40, 40}));
    tst::caseExample("Test 3: the very first car is on Road B",
                     tst::makeCars({1, 2, 3}, {3, 4, 1}, {10, 20, 30}));
    tst::caseStress();
    tst::caseAllRoadA();
    printf("\n%s\n", tst::failures == 0 ? "ALL PASSED" : "SOME TESTS FAILED");
    return tst::failures == 0 ? 0 : 1;
}
