#include "data_structures/structures.hpp"

class ZeroEvenOdd {
private:
    int n;
    int cur;
    mutex m;
    condition_variable cv;
    bool pzero = true;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        cur = 1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(cur<=n){
            unique_lock<mutex> lk(m);
            cv.wait(lk, [this]{return pzero || cur>n;});
            if(cur>n) return;
            printNumber(0);
            pzero = false;
            lk.unlock();
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while(cur<=n){
            unique_lock<mutex> lk(m);
            cv.wait(lk, [this]{return !pzero && cur%2 == 0 || cur>n;});
            if(cur>n) return;
            printNumber(cur++);
            pzero = true;
            lk.unlock();
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while(cur<=n){
            unique_lock<mutex> lk(m);
            cv.wait(lk, [this]{return !pzero && cur%2 || cur>n;});
            if(cur>n) return;
            printNumber(cur++);
            pzero = true;
            lk.unlock();
            cv.notify_all();
        }
    }
};