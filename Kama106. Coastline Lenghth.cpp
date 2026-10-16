/*https://kamacoder.com/problempage.php?pid=1178*/

#include "data_structures/structures.hpp"

class Solution{
public:
    int coastline(vector<vector<int>>& map){
        int islandCnt = 0;
        int neighborCnt = 0;
        for(int i=0; i<map.size(); ++i){
            for(int j=0; j<map[0].size(); ++j){
                if(map[i][j]){
                    ++islandCnt;
                    if(j + 1 < map[0].size() &&map[i][j+1] == 1){
                        ++neighborCnt;
                    }
                    if(j-1>=0 && map[i][j-1] == 1){
                        ++neighborCnt;
                    }
                    if(i-1>=0 && map[i-1][j] == 1){
                        ++neighborCnt;
                    }
                    if(i+1<map.size() && map[i+1][j] == 1){
                        ++neighborCnt;
                    }
                }
            }
        }
        return 4*islandCnt - neighborCnt;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m, 0));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> map[i][j];
        }
    }
    Solution s;
    cout << s.coastline(map) << endl;
    return 0;
}