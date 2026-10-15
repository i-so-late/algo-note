#include "data_structures/structures.hpp"

class Solution{
public:
    int dirctX[4] = {0, 1, 0, -1};
    int dirctY[4] = {1, 0, -1, 0};

    int bfs(const vector<vector<int>>& map, vector<vector<int>>& rec, int curX, int curY){
        queue<int> que;
        int res = 0;
        que.push(curX); que.push(curY);
        rec[curX][curY] = 1;
        res++;
        bool isIso = true;
        while (!que.empty())
        {
            curX = que.front(); que.pop();
            curY = que.front(); que.pop();
            for(int i=0; i<4; ++i){
                int tmpX = curX + dirctX[i];
                int tmpY = curY + dirctY[i];
                if(tmpX <= 0 || tmpY <=0 || tmpX >= map.size()-1 || tmpY >= map[0].size()-1){
                    if(map[tmpX][tmpY])
                        isIso = false;
                    continue;
                }
                if(map[tmpX][tmpY] == 1 && rec[tmpX][tmpY] == 0){
                    que.push(tmpX); que.push(tmpY);
                    rec[tmpX][tmpY] = 1;
                    res++;
                }
            }
        }
        return isIso?res:0;
    }

    int countIsland(const vector<vector<int>>& map){
        int n, m;
        n = map.size();
        m = map[0].size();
        int res = 0;
        vector<vector<int>> rec(n, vector<int>(m, 0));
        for(int i=1; i<n-1; ++i){
            for(int j=1; j<m-1; ++j){
                if(rec[i][j] || map[i][j] == 0) continue;
                res += bfs(map, rec, i, j);
            }
        }
        return res;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m, 0));
    int tmp;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> tmp;
            map[i][j] = tmp;
        }
    }
    Solution s;
    cout << s.countIsland(map) << endl;
    return 0;
}