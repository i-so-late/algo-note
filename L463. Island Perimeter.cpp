#include "data_structures/structures.hpp"

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int islandCnt = 0;
        int neighborCnt = 0;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j]){
                    ++islandCnt;
                    if(j + 1 < grid[0].size() &&grid[i][j+1] == 1){
                        ++neighborCnt;
                    }
                    if(j-1>=0 && grid[i][j-1] == 1){
                        ++neighborCnt;
                    }
                    if(i-1>=0 && grid[i-1][j] == 1){
                        ++neighborCnt;
                    }
                    if(i+1<grid.size() && grid[i+1][j] == 1){
                        ++neighborCnt;
                    }
                }
            }
        }
        return 4*islandCnt - neighborCnt;
    }
};