#include "data_structures/structures.hpp"

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<dp.size(); ++i){
            int j = 1;
            while(j<=i){
                dp[i] += dp[j-1]*dp[i-j];
                j++;
            }
        }
        return dp[n];
    }
};