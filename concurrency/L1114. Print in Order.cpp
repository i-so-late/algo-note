#include "data_structures/structures.hpp"

class Foo {
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        unique_lock<mutex> lk(m);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sec2 = true;
        lk.unlock();
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        
        unique_lock<mutex> lk(m);
        cv.wait(lk, [this]{ return sec2;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        thi3 = true;
        lk.unlock();
        cv.notify_one();
    }

    void third(function<void()> printThird) {
        
        unique_lock<mutex> lk(m);
        cv.wait(lk, [this]{return thi3; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    mutex m;
    condition_variable cv;
    bool sec2 = false;
    bool thi3 = false;
};