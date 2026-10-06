#include "data_structures/structures.hpp"

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(int i=0; i<stones.size(); ++i){
            sum += stones[i];
        }       
        int sub_sum = sum/2;
        vector<int> dp(sub_sum+1, 0);
        for(int i=0; i<stones.size(); ++i){
            for(int j=sub_sum; j >= stones[i]; --j){
                dp[j] = max(dp[j], dp[j-stones[i]]+stones[i]);
            }
        }
        return abs(sum-dp.back()-dp.back());
    }
};