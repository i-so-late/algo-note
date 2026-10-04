#include "data_structures/structures.hpp"

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        for(int j=1; j<=n; ++j){
            dp[j] = j;
        }
        for(int i=2; i*i<=n; ++i){
            for(int j=1; j<=n; ++j){
                if(j>=i*i) dp[j] = min(dp[j], dp[j-i*i] + 1);
            }
        }
        return dp.back();
    }
};