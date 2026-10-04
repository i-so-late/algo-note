#include <data_structures/structures>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, 0));
        for(int j=0; j<amount+1; ++j){
            if(j%coins[0]) dp[0][j] = -1;
            else dp[0][j] = j/coins[0];
        }
        for(int i=1; i<coins.size(); ++i){
            for(int j=1; j<amount+1; ++j){
                if(j<coins[i]) dp[i][j] = dp[i-1][j];
                else{
                    if(dp[i][j-coins[i]]==-1) dp[i][j] = dp[i-1][j];
                    else if(dp[i-1][j]==-1) dp[i][j] = dp[i][j-coins[i]]+1;
                    else dp[i][j] = min(dp[i][j] = dp[i-1][j], dp[i][j-coins[i]]+1);
                }
            }
        }
        return dp[coins.size()-1][amount];
    }
};