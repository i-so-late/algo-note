#include "data_structures/structures.hpp"

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int l = 0, r = 1;
        int res = 1;
        for(int i=1; i<nums.size(); ++i){
            if(nums[i] > nums[i-1]) r++;
            else{
                res = max(res, r-l);
                l = r;
                r++;
            }
        }
        res = max(res, r-l);
        return res;
    }
};