#include "data_structures/structures.hpp"

class H2O {
private:
    mutex m;
    condition_variable cv;
    int hcnt;

public:
    H2O() {
        hcnt = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        unique_lock<mutex> lk(m);
        cv.wait(lk, [this]{ return hcnt < 2 ;});
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        hcnt++;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        
        unique_lock<mutex> lk(m);
        cv.wait(lk, [this]{ return hcnt==2; });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        hcnt = 0;
        cv.notify_all();
    }
};