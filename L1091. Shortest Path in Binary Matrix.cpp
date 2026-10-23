#include "data_structures/structures.hpp"

// class Solution {
//     int dirctX[8] = {1, 1, 1, 0, 0, -1, -1, -1};
//     int dirctY[8] = {1, 0, -1, 1, -1, 1, 0, -1};
// public:
//     int bfs(const vector<vector<int>>& grid){
//         if(grid[0][0]) return -1;
//         queue<pair<int, int>> que;
//         int n = grid.size();
//         vector<vector<int>> visited(n, vector<int>(n, INT_MAX));
//         que.push({0, 0});
//         int res = 0;
//         while(!que.empty()){
//             int queSize = que.size();
//             res++;
//             while(queSize--){
//                 auto cur = que.front(); que.pop();
//                 if(cur.first== n-1 && cur.second == n-1){
//                     return res;
//                 }
//                 for(int i=0; i<8; ++i){
//                     int newX = cur.first + dirctX[i];
//                     int newY = cur.second + dirctY[i];
//                     if(newX > n-1 || newY > n-1 || newX < 0 || newY < 0) continue;
//                     if(grid[newX][newY] == 0 && visited[newX][newY] > res){
//                         que.push({newX, newY});
//                         visited[newX][newY] = res;
//                     }
//                 }
//             }
//         }
//         return -1;
//     }

//     int shortestPathBinaryMatrix(const vector<vector<int>>& grid) {
//         return bfs(grid);
//     }
// };

struct SPBM{
    int x, y, g, f;
    bool operator<(const SPBM& s) const { return this->f > s.f; }
};

class Solution {
    int dirctX[8] = {1, 1, 1, 0, 0, -1, -1, -1};
    int dirctY[8] = {1, 0, -1, 1, -1, 1, 0, -1};
public:
    int heuristic(int x, int y, int n){
        return max(n-1-x, n-1-y);
    }

    int Astar(const vector<vector<int>>& grid){
        priority_queue<SPBM> pq;
        int n = grid.size();
        vector<vector<int>> visit(n, vector<int>(n, INT_MAX));
        pq.push({0,0,1,1+heuristic(0, 0, n)});
        visit[0][0] = 1;
        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            if(cur.x == n-1 && cur.y == n-1){
                return cur.g;
            }
            for(int i=0; i<8; ++i){
                int newX = cur.x + dirctX[i];
                int newY = cur.y + dirctY[i];
                if(newX > n-1 || newY > n-1 || newX < 0 || newY < 0) continue;
                if(grid[newX][newY]==0 && cur.g+1 < visit[newX][newY]){
                    visit[newX][newY] = cur.g+1;
                    pq.push({newX, newY, cur.g+1, cur.g+1 + heuristic(newX, newY, n)});
                }
            }
        }
        return -1;
    }

    int shortestPathBinaryMatrix(const vector<vector<int>>& grid) {
        if(grid[0][0]) return -1;
        return Astar(grid);
    }
};

int main(){
    Solution s;
    s.shortestPathBinaryMatrix({{0,1} , {1,0}});
}