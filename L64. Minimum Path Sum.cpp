#include "data_structures/structures.hpp"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> dp(grid[0].size(), 0);
        dp[0] = grid[0][0];
        for(int j=1; j<grid[0].size(); ++j){
            dp[j] = grid[0][j] + dp[j-1];
        }
        for(int i=1; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(j==0){
                    dp[j] = dp[j] + grid[i][j];
                }
                else{
                    dp[j] = min(dp[j-1], dp[j]) + grid[i][j];
                }
            }
        }
        return dp.back();
    }
};