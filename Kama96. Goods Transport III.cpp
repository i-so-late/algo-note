/*https://kamacoder.com/problempage.php?pid=1154*/

#include "data_structures/structures.hpp"

int main(){
    int n, m, s, t, v;
    cin >> n >> m;
    vector<array<int, 3>> map;
    for(int i=0; i<m; ++i){
        cin >> s >> t >> v;
        map.push_back({s, t, v});
    }
    int src, dst, k;
    cin >> src >> dst >> k;

    vector<int> minDist(n+1, INT_MAX);
    minDist[src] = 0;
    vector<int> minDist_copy;
    for(int i=0; i<k+1; ++i){
        minDist_copy = minDist;
        for(auto& edge: map){
            int s = edge[0];
            int d = edge[1];
            int v = edge[2];

            if(minDist_copy[s] == INT_MAX) continue;
            if(minDist_copy[s]+v < minDist[d]){
                minDist[d] = minDist_copy[s] + v;
            }
        }
    }
    if(minDist[dst] == INT_MAX) cout << "unreachable" ;
    else cout << minDist[dst];
    return 0;
}