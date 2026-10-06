#include "data_structures/structures.hpp"

class Solution {
public:
    int sum(vector<int>& v){
        int res = 0;
        for(auto p:v){
            res += p;
        }
        return res;
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        size_t i;
        for(i=0; i<nums.size(); ++i){
            if(nums[i] > 0) break;
            nums[i] = 0-nums[i];
            k--;
            if(k<=0) return sum(nums);    
        } 
        sort(nums.begin(), nums.end());
        if(k>0){
            if(k%2) nums[0] = 0-nums[0];
        }
        return sum(nums);
    }
};