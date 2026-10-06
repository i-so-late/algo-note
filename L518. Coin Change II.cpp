#include "data_structures/structures.hpp"

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<uint64_t>> dp(coins.size(), vector<uint64_t>(amount+1,0));
        for(int j=0; j<=amount;j++){
            dp[0][j] = j%coins[0] ? 0 : 1;
        }
        for(int i=0; i<coins.size(); ++i){
            dp[i][0] = 1;
        }
        for(int i=1; i<coins.size(); ++i){
            for(int j=0; j<=amount; ++j){
                if(coins[i] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j]+dp[i][j-coins[i]];
            }
        }
        return dp[coins.size()-1][amount];
    }
};