#include "data_structures/structures.hpp"

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); ++i){
            sum += nums[i];
        }        
        if(sum%2) return false;
        else sum = sum/2;

        sort(nums.begin(), nums.end());
        vector<int> dp(sum+1, 0);
        for(int i=0; i<nums.size(); ++i){
            for(int j=sum; j>=nums[i]; --j){
                dp[j] = max(dp[j], dp[j-nums[i]]+nums[i]);
            }
        }
        if(dp[sum]==sum) return true;
        return false;
    }
};