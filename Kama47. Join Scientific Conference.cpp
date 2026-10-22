/*https://kamacoder.com/problempage.php?pid=1047*/

#include "data_structures/structures.hpp"

/*
int main(){
    int n,m,s,e,v;
    cin >> n >> m;
    vector<vector<int>> grid(n+1, vector<int>(n+1, INT_MAX));
    for(int i=0; i<m; ++i){
        cin >> s >> e >> v;
        grid[s][e] = v;
    }
    int src = 1; int des = n;
    
    vector<int> minDist(n+1, INT_MAX);
    minDist[src] = 0;
    vector<bool> visited(n+1, false);
    
    for(int i=0; i<n; ++i){
        int minD = INT_MAX;
        int cur = -1;
        for(int i=1; i<=n; ++i){
            if(!visited[i] && minDist[i] < minD){
                cur = i;
                minD = minDist[i];
            }
        }
        if(cur == -1){
            cout << -1 ;
            return 0;
        }
        visited[cur] = true;
        
        for(int i=1; i<=n; ++i){
            if(!visited[i] && grid[cur][i]!=INT_MAX && grid[cur][i]+minDist[cur] < minDist[i]){
                minDist[i] = grid[cur][i]+minDist[cur];
            }
        }
    }
    cout << minDist[des];
    return 0;
}
    */

int main(){
    int n,m,s,e,v;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adjList(n+1);
    for(int i=0; i<m; ++i){
        cin >> s >> e >> v;
        adjList[s].push_back({e, v});
    }

    vector<int> minDist(n+1, INT_MAX);
    minDist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 1});

    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();
        if(d>minDist[u]) continue;
        for(auto [e, v] : adjList[u]){
            if(minDist[u]+v < minDist[e]){
                minDist[e] = minDist[u]+v;
                pq.push({minDist[e], e});
            }
        }
    }
    if(minDist[n] == INT_MAX) cout << -1;
    else cout << minDist[n];
    return 0;
}