/*https://kamacoder.com/problempage.php?pid=1153*/

#include "data_structures/structures.hpp"

int main(){
    int n, m, s, t, v;
    cin >> n >> m;
    vector<array<int, 3>> map;
    for(int i=0; i<m; ++i){
        cin >> s >> t >> v;
        map.push_back({s, t, v});
    }

    vector<int> minDist(n+1, INT_MAX);
    minDist[1] = 0;
    int minDistN = 0;
    for(int i=0; i<n; ++i){
        for(auto& edge: map){
            int src = edge[0];
            int des = edge[1];
            int val = edge[2];

            if(minDist[src] == INT_MAX) continue;
            if(minDist[src]+val < minDist[des]){
                minDist[des] = minDist[src] + val;
            }
        }
        if(i==n-2){
            minDistN = minDist[n];
        }
    }
    if(minDist[n] == INT_MAX) cout << "unconnected" ;
    else if(minDist[n] != minDistN) cout << "circle" ;
    else cout << minDist[n];
    return 0;
}