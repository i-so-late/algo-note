/*https://kamacoder.com/problempage.php?pid=1155*/

#include "data_structures/structures.hpp"

int main(){
    int n, m;
    cin >> n >> m;
    int u, v, w;
    vector<vector<vector<int>>> grid(n+1, vector<vector<int>>(n+1, vector<int>(n+1, 10001)));
    for(int i=0; i<m; ++i){
        cin >> u >> v >> w;
        grid[u][v][0] = w;
        grid[v][u][0] = w;
    }
    
    int q;
    cin >> q;
    vector<pair<int, int>> sightseeing;
    int a, b;
    for(int i=0; i<q; ++i){
        cin >> a >> b;
        sightseeing.push_back({a, b});
    }

    for(int k=1; k<=n; ++k){
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                grid[i][j][k] = min(grid[i][k][k-1] + grid[k][j][k-1], grid[i][j][k-1]);
            }
        }
    }
    for(auto [a, b] : sightseeing){
        if(grid[a][b][n] == 10001) cout << -1 << endl;
        else cout << grid[a][b][n] << endl;
    }
    return 0;
}
