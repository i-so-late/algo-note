/*https://kamacoder.com/problempage.php?pid=1191*/

#include "data_structures/structures.hpp"

int main(){
    int n, m, s, t;
    cin >> n >> m;
    vector<vector<int>> adjList(n, vector<int>{});
    vector<int> minDist(n, 0);
    vector<int> res;
    for(int i=0; i<m; ++i){
        cin >> s >> t;
        adjList[s].push_back(t);
        minDist[t]++;
    }
    queue<int> que;
    for(int i=0; i<n; ++i){
        if(minDist[i] == 0) que.push(i);
    }
    while(!que.empty()){
        int tmp = que.front();
        que.pop();
        res.push_back(tmp);
        for(auto i:adjList[tmp]){
            minDist[i]--;
            if(minDist[i]==0) que.push(i);
        }
    }
    if(res.size()!=n){
        cout << -1;
        return 0;
    }
    for(int i=0; i<res.size(); ++i){
        if(i==res.size()-1) cout << res[i] << endl;
        else cout << res[i] << ' ';
    }
    return 0;
}