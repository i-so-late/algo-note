/*https://kamacoder.com/problempage.php?pid=1171*/

#include "data_structures/structures.hpp"

class Solution{
public:
    void dfs(const vector<vector<int>>& map, vector<vector<int>>& rec, int curX, int curY){
        if(curX<0 || curX >= map.size() || curY < 0 || curY >= map[0].size() || map[curX][curY] == 0 || rec[curX][curY] == 1) return;
        else
            rec[curX][curY] = 1;
        dfs(map, rec, curX, curY+1);
        dfs(map, rec, curX, curY-1);
        dfs(map, rec, curX-1, curY);
        dfs(map, rec, curX+1, curY);
        return;
    }
    void bfs(const vector<vector<int>>& map, vector<vector<int>>& rec, int curX, int curY){
        queue<pair<int, int>> que;
        que.push({curX, curY});
        rec[curX][curY] = 1;
        while (!que.empty())
        {
            pair<int, int> tmp = que.front();
            que.pop();
            if(tmp.first - 1 >= 0 && map[tmp.first-1][tmp.second] == 1 && rec[tmp.first-1][tmp.second] == 0){
                que.push({tmp.first-1, tmp.second});
                rec[tmp.first-1][tmp.second] = 1;
            }
            if(tmp.first + 1 < map.size() && map[tmp.first+1][tmp.second] == 1 && rec[tmp.first+1][tmp.second] == 0){
                que.push({tmp.first+1, tmp.second});
                rec[tmp.first+1][tmp.second] = 1;
            }
            if(tmp.second - 1 >= 0 && map[tmp.first][tmp.second-1] == 1 && rec[tmp.first][tmp.second-1] == 0){
                que.push({tmp.first, tmp.second-1});
                rec[tmp.first][tmp.second-1] = 1;
            }
            if(tmp.second + 1 < map[0].size() && map[tmp.first][tmp.second+1] == 1 && rec[tmp.first][tmp.second+1] == 0){
                que.push({tmp.first, tmp.second+1});
                rec[tmp.first][tmp.second+1] = 1;
            }
        }
        return;
    }

    int countIsland(const vector<vector<int>>& map){
        int n, m;
        n = map.size();
        m = map[0].size();
        int res = 0;
        vector<vector<int>> rec(n, vector<int>(m, 0));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(rec[i][j] || map[i][j] == 0) continue;
                res++;
                //dfs(map, rec, i, j);
                bfs(map, rec, i, j);
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