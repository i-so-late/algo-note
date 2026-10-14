#include "data_structures/structures.hpp"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto n: nums){
            res ^= n;
        }
        return res;
    }
};