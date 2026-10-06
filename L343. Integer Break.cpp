#include "data_structures/structures.hpp"

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 1;
        for(int i=3; i<dp.size(); ++i){
            int j = 1;
            while(j<=i){
                dp[i] = max(dp[i], dp[j]*dp[i-j]);
                dp[i] = max(dp[i], j*(i-j));
                dp[i] = max(dp[i], dp[j]*(i-j));
                j++;
            }
            //cout<< dp[i]<<" ";
        }
        return dp[n];
    }
};