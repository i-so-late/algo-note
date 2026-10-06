#include "data_structures/structures.hpp"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n, 1));
        int ob = 1;
        for(int i=0; i<m; ++i){
            if(obstacleGrid[i][0] == 1) {
                ob = 0;
            }
            dp[i][0] = ob;
        }
        ob = 1;
        for(int j=0; j<n; ++j){
            if(obstacleGrid[0][j] == 1) {
                ob = 0;
            }
            dp[0][j] = ob;
        }
        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
            }
        }
        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                if(dp[i][j] == 0) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};