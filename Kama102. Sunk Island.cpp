/*https://kamacoder.com/problempage.php?pid=1174*/

#include "data_structures/structures.hpp"

class Solution{
public:
    int dirctX[4] = {0, 1, 0, -1};
    int dirctY[4] = {1, 0, -1, 0};

    void bfs(const vector<vector<int>>& map, vector<vector<int>>& rec, int curX, int curY){
        queue<int> que;
        que.push(curX); que.push(curY);
        rec[curX][curY] = 1;
        while (!que.empty())
        {
            curX = que.front(); que.pop();
            curY = que.front(); que.pop();
            for(int i=0; i<4; ++i){
                int tmpX = curX + dirctX[i];
                int tmpY = curY + dirctY[i];
                if(tmpX <= 0 || tmpY <=0 || tmpX >= map.size()-1 || tmpY >= map[0].size()-1){
                    continue;
                }
                if(map[tmpX][tmpY] == 1 && rec[tmpX][tmpY] == 0){
                    que.push(tmpX); que.push(tmpY);
                    rec[tmpX][tmpY] = 1;
                }
            }
        }
        return ;
    }

    void sunkIsland(const vector<vector<int>>& map, vector<vector<int>>& rec){
        int n, m;
        n = map.size();
        m = map[0].size();
        for(int i=0; i<m; ++i){
            if(rec[0][i] || map[0][i] == 0) continue;
                bfs(map, rec, 0, i);
        }
        for(int i=0; i<m; ++i){
            if(rec[n-1][i] || map[n-1][i] == 0) continue;
                bfs(map, rec, n-1, i);
        }
        for(int i=0; i<n; ++i){
            if(rec[i][0] || map[i][0] == 0) continue;
                bfs(map, rec, i, 0);
        }
        for(int i=0; i<n; ++i){
            if(rec[i][m-1] || map[i][m-1] == 0) continue;
                bfs(map, rec, i, m-1);
        }
        return;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m, 0));
    vector<vector<int>> rec(n, vector<int>(m, 0));
    int tmp;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> tmp;
            map[i][j] = tmp;
        }
    }
    Solution s;
    s.sunkIsland(map, rec);
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(j==m-1) cout << rec[i][j];
            else cout << rec[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}