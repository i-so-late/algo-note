/*https://kamacoder.com/problempage.php?pid=1176*/

#include "data_structures/structures.hpp"

class Solution{
public:
    int dfs(const vector<vector<int>>& map, vector<vector<int>>& rec, int curX, int curY){
        if(curX<0 || curX >= map.size() || curY < 0 || curY >= map[0].size() || map[curX][curY] == 0 || rec[curX][curY] == 1) return 0;
        int res = 1;
        rec[curX][curY] = 1;
        res += dfs(map, rec, curX, curY+1);
        res += dfs(map, rec, curX, curY-1);
        res += dfs(map, rec, curX-1, curY);
        res += dfs(map, rec, curX+1, curY);
        return res;
    }

    int artifactIsland(vector<vector<int>>& map){
        int n, m;
        n = map.size();
        m = map[0].size();
        int res = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(map[i][j] == 0){
                    vector<vector<int>> rec(n, vector<int>(m, 0));
                    map[i][j] = 1;
                    res = max(res, dfs(map, rec, i, j));
                    map[i][j] = 0;
                }
            }
        }
        if (res == 0) return n*m;
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
    cout << s.artifactIsland(map) << endl;
    return 0;
}