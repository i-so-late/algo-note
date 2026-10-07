#include "data_structures/structures.hpp"

class Solution {
public:
    int reverse(int x) {
        int64_t res = 0;
        int64_t tmp;
        while(x){
            tmp = x%10;
            x = x/10;
            res = res*10+tmp;
        }
        return res > INT_MAX || res <INT_MIN ? 0 : res;
    }
};