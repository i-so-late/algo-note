#include "data_structures/structures.hpp"

class FizzBuzz {
private:
    mutex m;
    condition_variable cv;
    int n;
    int i;

public:
    FizzBuzz(int n) {
        this->n = n;
        i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(true){
            unique_lock<mutex> lk(m);
            cv.wait(lk, [this]{ return i%3==0 && i%5 || i>n; });
            if(i>n) return;
            printFizz();
            ++i;
            lk.unlock();
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(true){
            unique_lock<mutex> lk(m);
            cv.wait(lk, [this]{ return i%3 && i%5==0 || i>n; });
            if(i>n) return;
            printBuzz();
            ++i;
            lk.unlock();
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while(true){
            unique_lock<mutex> lk(m);
            cv.wait(lk, [this]{ return i%3==0 && i%5==0 || i>n; });
            if(i>n) return;
            printFizzBuzz();
            ++i;
            lk.unlock();
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(true){
            unique_lock<mutex> lk(m);
            cv.wait(lk, [this]{ return i%3 && i%5 || i>n; });
            if(i>n) return;
            printNumber(i);
            ++i;
            lk.unlock();
            cv.notify_all();
        }
    }
};