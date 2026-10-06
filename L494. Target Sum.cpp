#include "data_structures/structures.hpp"

class Solution {
public:
    //sub1-sub2 = target
    //sub1+sub2 = sum; sub2 = sum-sub1;
    //sub1 = (sum + target)/2
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto p: nums){
            sum += p;
        }
        if((sum+target)%2) return 0;
        if(abs(target) > sum) return 0;
        int sub1 = (sum + target)/2;
        vector<int> dp(sub1+1, 0);
        dp[0] = 1;
        for(int i=0; i<nums.size(); ++i){
            for(int j=sub1; j>=nums[i]; --j){
                dp[j] = dp[j] + dp[j-nums[i]];
            }
        }
        return dp[sub1];
    }
};