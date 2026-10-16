/*https://kamacoder.com/problempage.php?pid=1175*/

#include "data_structures/structures.hpp"

class Solution{
public:
    void dfs(const vector<vector<int>>& map, vector<vector<int>>& rec, int curX, int curY, bool& firstBdr, bool& secondBdr){
        if(curX<0 || curX >= map.size() || curY < 0 || curY >= map[0].size() || rec[curX][curY] == 1) return;
        rec[curX][curY] = 1;
        if(curX == 0 || curY == 0) firstBdr = true;
        if(curX == map.size()-1 || curY == map[0].size()-1) secondBdr = true;
        if(curY + 1 < map[0].size() && map[curX][curY+1]<=map[curX][curY])
            dfs(map, rec, curX, curY+1, firstBdr, secondBdr);
        if(curY - 1 >= 0 && map[curX][curY-1]<=map[curX][curY])
            dfs(map, rec, curX, curY-1, firstBdr, secondBdr);
        if(curX - 1 >= 0 && map[curX-1][curY]<=map[curX][curY])
            dfs(map, rec, curX-1, curY, firstBdr, secondBdr);
        if(curX + 1 < map.size() && map[curX+1][curY]<=map[curX][curY])
            dfs(map, rec, curX+1, curY, firstBdr, secondBdr);
        return;
    }

    vector<pair<int, int>> fllowingWater(const vector<vector<int>>& map){
        int n, m;
        n = map.size();
        m = map[0].size();
        vector<pair<int, int>> res;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                vector<vector<int>> rec(n, vector<int>(m, 0));
                bool firstBdr = false, secondBdr = false;
                dfs(map, rec, i, j, firstBdr, secondBdr);
                if(firstBdr && secondBdr) res.emplace_back(i, j);
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
    auto res = s.fllowingWater(map);
    for(auto r: res){
        cout << r.first << ' ' << r.second << endl;
    }
    return 0;
}