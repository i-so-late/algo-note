#include "data_structures/structures.hpp"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] == 0){
                continue;
            }
            nums[left] = nums[i];
            left++;
        }
        for(; left<nums.size(); left++) nums[left] = 0;
        return;
    }
};