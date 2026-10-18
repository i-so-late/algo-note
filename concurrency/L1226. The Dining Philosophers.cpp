#include "data_structures/structures.hpp"

class DiningPhilosophers {

    vector<mutex> ms;
public:
    DiningPhilosophers() : ms(5) {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		scoped_lock lk(ms[philosopher], ms[(philosopher+1)%5]);
        pickLeftFork(); pickRightFork();
        eat();
        putLeftFork(); putRightFork();
    }
};

/*
//use C++17 std::scoped_lock
class DiningPhilosophers {

    vector<mutex> ms;
public:
    DiningPhilosophers() : ms(5) {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		scoped_lock lk(ms[philosopher], ms[(philosopher+1)%5]);
        pickLeftFork(); pickRightFork();
        eat();
        putLeftFork(); putRightFork();
    }
};
*/