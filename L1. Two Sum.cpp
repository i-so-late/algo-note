#include "data_structures/structures.hpp"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        for(int i=0; i<nums.size(); i++){
            int sub = target-nums[i];
            if(mpp.find(sub)!=mpp.end()){
                return {mpp[sub], i};
            }else{
                mpp[nums[i]] = i;
            }
        }
        return {};
    }
};