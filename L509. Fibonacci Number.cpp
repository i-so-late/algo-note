#include "data_structures/structures.hpp"

class Solution {
public:
    int F(int first, int second, int n){
        if(n == 0) return 0;
        if(n <= 2) return 1;
        else if(n==3) return first + second;
        return F(second, first+second, --n);
    }
    int fib(int n) {
        return F(1,1,n);
    }
};