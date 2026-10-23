/*https://kamacoder.com/problempage.php?pid=1152*/

#include "data_structures/structures.hpp"

// int main(){
//     int n, m, s, t, v;
//     cin >> n >> m;
//     vector<array<int, 3>> map;
//     for(int i=0; i<m; ++i){
//         cin >> s >> t >> v;
//         map.push_back({s, t, v});
//     }

//     vector<int> minDist(n+1, INT_MAX);
//     minDist[1] = 0;
//     for(int i=0; i<n-1; ++i){
//         for(auto& edge: map){
//             int src = edge[0];
//             int des = edge[1];
//             int val = edge[2];

//             if(minDist[src] == INT_MAX) continue;
//             if(minDist[src]+val < minDist[des]){
//                 minDist[des] = minDist[src] + val;
//             }
//         }
//     }
//     if(minDist[n] == INT_MAX) cout << "unconnected" ;
//     else cout << minDist[n];
//     return 0;
// }

int main(){
    int n, m, s, t, v;
    cin >> n >> m;
    vector<vector<pair<int ,int>>> map(n+1);
    for(int i=0; i<m; ++i){
        cin >> s >> t >> v;
        map[s].push_back({t, v});
    }

    queue<int> que;
    vector<bool> isInQue(n+1, false);
    vector<int> minDist(n+1, INT_MAX);

    que.push(1);
    minDist[1] = 0;

    while(!que.empty()){
        int tmp = que.front(); que.pop();
        isInQue[tmp] = false;
        for(auto [e, v] : map[tmp]){
            if(minDist[e] > minDist[tmp]+v){
                minDist[e] = minDist[tmp] + v;
                if(!isInQue[e]){
                    que.push(e);
                    isInQue[e] = true;
                }
            }
        }
    }
    if(minDist[n] == INT_MAX) cout << "unconnected" ;
    else cout << minDist[n];
    return 0;
}