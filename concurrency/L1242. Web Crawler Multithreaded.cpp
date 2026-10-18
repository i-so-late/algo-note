// LeetCode 1242. Web Crawler Multithreaded (Premium), local practice version
// Build and run: g++ -std=c++20 -O2 -pthread -I . "concurrency/L1242. Web Crawler Multithreaded.cpp" -o crawler && ./crawler
//
// Problem:
//   Given a start link startUrl and an HtmlParser, implement crawl():
//   return every link reachable from startUrl that has the same hostname as startUrl (including startUrl itself), in any order.
//
//   - htmlParser.getUrls(url) returns all links contained in the page at url.
//     It simulates an HTTP request: a blocking call that takes about 15ms each time.
//     Crawling one page at a time on a single thread will time out, so send requests from several threads at once.
//   - Links have the form http://hostname/path or http://hostname, with no port number.
//     The hostname is the part between "http://" and the first "/" after it,
//     e.g. the hostname of http://news.yahoo.com/news/topics/ is news.yahoo.com.
//   - Only crawl links with the same hostname as startUrl: links on other hostnames are neither returned nor passed to getUrls.
//   - Do not crawl the same link twice (pages may link to each other and form cycles).
//   - Learn about page contents only through getUrls; do not rely on HtmlParser's internal implementation.

#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <memory>
#include <random>
#include "data_structures/structures.hpp"

// -------------------- Simulated HtmlParser (stands in for the interface LeetCode provides, no need to change) --------------------
struct ParserState {
    unordered_map<string, vector<string>> graph;
    int delayMs = 15;
    atomic<int> inFlight{0};
    atomic<int> maxInFlight{0};
    mutex m;
    unordered_map<string, int> fetchCount;
};

class HtmlParser {
    shared_ptr<ParserState> s;
public:
    explicit HtmlParser(shared_ptr<ParserState> state) : s(move(state)) {}

    // Returns all links in the page at url. Thread-safe: several threads may call it at the same time. Each call blocks for about 15ms.
    vector<string> getUrls(string url) {
        int now = ++s->inFlight;
        int prev = s->maxInFlight.load();
        while (now > prev && !s->maxInFlight.compare_exchange_weak(prev, now)) {}
        {
            lock_guard<mutex> lk(s->m);
            ++s->fetchCount[url];
        }
        this_thread::sleep_for(chrono::milliseconds(s->delayMs));
        --s->inFlight;
        auto it = s->graph.find(url);
        if (it == s->graph.end()) return {};
        return it->second;
    }
};

// ==================== Your implementation goes here ====================
class Solution {
    string hostOf(const string& s){
        size_t p = s.find('/', 7);
        if(p == string::npos)
            return s.substr(7);
        return s.substr(7, p-7);
    }

public:

    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        queue<string> que;
        unordered_set<string> us;
        vector<string> ans;
        string hostOfStart = hostOf(startUrl);
        que.push(startUrl);
        us.emplace(startUrl);
        ans.push_back(startUrl);
        while(!que.empty()){
            int n = que.size();
            vector<future<vector<string>>> fus;
            while(n){
                string tmp = que.front();
                que.pop();
                fus.push_back(async(launch::async, [&htmlParser, tmp]{ return htmlParser.getUrls(tmp); }));
                n--;
            }
            for(auto& f : fus){
                vector<string> res = f.get();
                for(const auto& s: res){
                    if(us.find(s) == us.end() && hostOf(s) == hostOfStart){
                        us.emplace(s);
                        que.push(s);
                        ans.push_back(s);
                    }
                }
            }
        }
        return ans;
    }
};
// ==================== End of implementation ====================


// -------------------- Tests below, no need to change --------------------
namespace tst {

using Graph = unordered_map<string, vector<string>>;
int failures = 0;

void check(bool ok, const string& what) {
    printf("  [%s] %s\n", ok ? "PASS" : "FAIL", what.c_str());
    if (!ok) ++failures;
}

void startWatchdog(int seconds) {
    thread([seconds] {
        this_thread::sleep_for(chrono::seconds(seconds));
        printf("\nTIMEOUT: did not finish within %d seconds, a thread may be blocked forever (deadlock / missed notify / did not terminate properly)\n", seconds);
        fflush(stdout);
        _Exit(1);
    }).detach();
}

string hostOf(const string& url) {
    size_t p = url.find('/', 7);
    return p == string::npos ? url.substr(7) : url.substr(7, p - 7);
}

vector<string> expectedCrawl(const Graph& g, const string& start) {
    string h = hostOf(start);
    unordered_set<string> seen{start};
    queue<string> q;
    q.push(start);
    while (!q.empty()) {
        string u = q.front();
        q.pop();
        auto it = g.find(u);
        if (it == g.end()) continue;
        for (const string& v : it->second)
            if (hostOf(v) == h && seen.insert(v).second) q.push(v);
    }
    vector<string> r(seen.begin(), seen.end());
    sort(r.begin(), r.end());
    return r;
}

void runCase(const string& name, const Graph& g, const string& start, bool checkSpeed) {
    printf("%s\n", name.c_str());
    auto state = make_shared<ParserState>();
    state->graph = g;
    HtmlParser parser(state);

    Solution sol;
    auto t0 = chrono::steady_clock::now();
    vector<string> got = sol.crawl(start, parser);
    long long ms = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - t0).count();

    vector<string> expected = expectedCrawl(g, start);
    vector<string> sortedGot = got;
    sort(sortedGot.begin(), sortedGot.end());
    bool noDup = adjacent_find(sortedGot.begin(), sortedGot.end()) == sortedGot.end();
    sortedGot.erase(unique(sortedGot.begin(), sortedGot.end()), sortedGot.end());

    check(sortedGot == expected, "returned link set is correct (expected " + to_string(expected.size()) + ", got " + to_string(sortedGot.size()) + " distinct)");
    check(noDup, "no duplicate links in the result");

    string h = hostOf(start);
    bool fetchedOnce = true, onlySameHost = true;
    int fetches = 0;
    for (const auto& kv : state->fetchCount) {
        fetches += kv.second;
        if (kv.second > 1) fetchedOnce = false;
        if (hostOf(kv.first) != h) onlySameHost = false;
    }
    check(fetchedOnce, "getUrls called at most once per link");
    check(onlySameHost, "getUrls never called on a link with another hostname");

    long long serialMs = (long long)fetches * state->delayMs;
    printf("     took %lld ms, serial would take about %lld ms, at most %d requests in flight at once\n", ms, serialMs, state->maxInFlight.load());
    if (checkSpeed) check(fetches >= (int)expected.size() && ms * 3 <= serialMs, "at least 3x faster than serial (requests really run concurrently)");
}

// Tests 1, 2: small example
void caseBasic() {
    Graph g = {
        {"http://news.yahoo.com/news/topics/", {"http://news.yahoo.com", "http://news.yahoo.com/news"}},
        {"http://news.google.com", {"http://news.yahoo.com/news/topics/", "http://news.yahoo.com/news"}},
        {"http://news.yahoo.com", {"http://news.yahoo.com/us"}},
    };
    runCase("Test 1: small example, starting from yahoo", g, "http://news.yahoo.com/news/topics/", false);
    runCase("Test 2: small example, starting from google (it only links to other hostnames)", g, "http://news.google.com", false);
}

// Test 3: hostname matching traps
void caseHostnameTraps() {
    Graph g = {
        {"http://shop.example.com/home", {
            "http://shop.example.com/cart",
            "http://shop.example.com",
            "http://shop.example.com.evil/phish",     // same prefix, different hostname
            "http://myshop.example.com/a",            // same suffix, different hostname
            "http://example.com/b",
            "http://other.com/shop.example.com/c",    // the path contains the hostname text
        }},
        {"http://shop.example.com/cart", {"http://shop.example.com/home", "http://shop.example.com/pay"}},
        // The trap pages below link to a page that only they point to: crawling any of them adds an extra /secret
        {"http://shop.example.com.evil/phish", {"http://shop.example.com/secret"}},
        {"http://myshop.example.com/a", {"http://shop.example.com/secret"}},
        {"http://example.com/b", {"http://shop.example.com/secret"}},
        {"http://other.com/shop.example.com/c", {"http://shop.example.com/secret"}},
    };
    runCase("Test 3: hostname matching traps (prefix / suffix / hostname inside the path)", g, "http://shop.example.com/home", false);
}

// Test 4: the start page has no links at all
void caseLonely() {
    Graph g;
    runCase("Test 4: the start page has no links at all", g, "http://lonely.com/", false);
}

// Test 5: one long chain, with a cycle
void caseChain() {
    Graph g;
    const int n = 20;
    for (int i = 0; i < n; ++i) {
        string u = "http://chain.test/" + to_string(i);
        g[u] = {"http://chain.test/" + to_string((i + 1) % n), "http://chain.test/0"};
    }
    runCase("Test 5: one long chain whose end links back to the start", g, "http://chain.test/0", false);
}

// Test 6: narrow then wide, the start has a single link and the next level suddenly fans out to 200
void caseNarrowThenWide() {
    Graph g;
    g["http://wide.test/"] = {"http://wide.test/hub"};
    vector<string> leaves;
    for (int i = 0; i < 200; ++i) {
        string leaf = "http://wide.test/leaf/" + to_string(i);
        leaves.push_back(leaf);
        g[leaf] = {"http://elsewhere.test/" + to_string(i), "http://wide.test/"};
    }
    g["http://wide.test/hub"] = leaves;
    runCase("Test 6: narrow then wide (1 -> 1 -> 200)", g, "http://wide.test/", true);
}

// Test 7: large random graph
void caseRandomLarge() {
    mt19937 rng(42);
    const int same = 400, other = 100, trap = 50;
    vector<string> pool;
    for (int i = 0; i < same; ++i) pool.push_back("http://crawl.test/page/" + to_string(i));
    for (int i = 0; i < other; ++i) pool.push_back("http://other" + to_string(i % 7) + ".test/p" + to_string(i));
    for (int i = 0; i < trap; ++i) pool.push_back("http://crawl.test.mirror/page/" + to_string(i));

    Graph g;
    uniform_int_distribution<int> pick(0, (int)pool.size() - 1), cnt(4, 6);
    for (int i = 0; i < (int)pool.size(); ++i) {
        vector<string>& links = g[pool[i]];
        if (i + 1 < same) links.push_back(pool[i + 1]);
        int k = cnt(rng);
        for (int j = 0; j < k; ++j) links.push_back(pool[pick(rng)]);
    }
    runCase("Test 7: large random graph (400 pages on the same hostname, mixed with other hostnames)", g, pool[0], true);
}

}  // namespace tst

int main() {
    tst::startWatchdog(30);
    tst::caseBasic();
    tst::caseHostnameTraps();
    tst::caseLonely();
    tst::caseChain();
    tst::caseNarrowThenWide();
    tst::caseRandomLarge();
    printf("\n%s\n", tst::failures == 0 ? "ALL PASSED" : "SOME TESTS FAILED");
    return tst::failures == 0 ? 0 : 1;
}
