#include "data_structures/structures.hpp"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        int i=1;
        for(; i<prices.size(); ++i){
            dp[i%2][0] = max(dp[(i-1)%2][0], prices[i]+dp[(i-1)%2][1]);
            dp[i%2][1] = max(dp[(i-1)%2][1], dp[(i-1)%2][0] - prices[i]);
        }
        return dp[(i-1)%2][0];
    }
};