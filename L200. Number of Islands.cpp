#include "data_structures/structures.hpp"

class Solution {
    int dirctX[4] = {1, -1, 0, 0};
    int dirctY[4] = {0, 0, 1, -1};
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
        if(visited[x][y]) return;
        visited[x][y] = true;
        for(int i=0; i<4; ++i){
            int newX = x + dirctX[i];
            int newY = y + dirctY[i];
            if(newX >= grid.size() || newY >= grid[0].size() || newX < 0 || newY < 0) continue;
            if(grid[newX][newY] == '1')
                dfs(grid, visited, newX, newY);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(!visited[i][j] && grid[i][j] == '1'){
                    res++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return res;
    }
};