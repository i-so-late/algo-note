#include "data_structures/structures.hpp"

class FooBar {
private:
    int n;
    mutex m;
    condition_variable cv;
    bool call_foo = true;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lk(m);
            cv.wait(lk, [this]{ return call_foo;});
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            call_foo = false;
            lk.unlock();
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lk(m);
            cv.wait(lk, [this]{ return !call_foo;});
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            call_foo = true;
            lk.unlock();
            cv.notify_one();
        }
    }
};