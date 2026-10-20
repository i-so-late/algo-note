/*https://kamacoder.com/problempage.php?pid=1182*/

#include "data_structures/structures.hpp"

vector<int> inDegree(1001, 0);
vector<int> father(1001, 0);

int find(int u){
    return u==father[u]? u : father[u] = find(father[u]);
}

void init( int n){
    for(int i=1; i<=n; ++i) father[i] = i;
}

void join(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return;
    father[v] = u;
}

bool isSame(int u, int v){
    u = find(u);
    v = find(v);
    return u==v;
}

bool isRemovedStillTree(int edge, const vector<vector<int>>& edges){
    for(int i=edges.size()-1; i>=0; --i){
        if(i==edge) continue;
        if(isSame(edges[i][0], edges[i][1])) return false;
        join(edges[i][0], edges[i][1]);
    }
    return true;
}

void dropCycle(const vector<vector<int>>& edges){
    for(int i=0; i<edges.size(); ++i){
        if(isSame(edges[i][0], edges[i][1])){
            cout << edges[i][0] << ' ' << edges[i][1] << endl;
            return; 
        }
        join(edges[i][0], edges[i][1]);
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> edges(n, vector<int>(2, 0));
    for(int i=0; i<n; ++i){
        cin >> edges[i][0] >> edges[i][1]; 
        inDegree[edges[i][1]]++;
    }
    vector<int> tmp;
    for(int i=n-1; i>=0; --i){
        if(inDegree[edges[i][1]]>1) tmp.emplace_back(i);
    }
    if(tmp.size() != 0){
        init(n);
        if(isRemovedStillTree(tmp[0], edges)){
            cout << edges[tmp[0]][0] << ' ' << edges[tmp[0]][1];
        }else{
            cout << edges[tmp[1]][0] << ' ' << edges[tmp[1]][1];
        }
    }
    else{
        init(n);
        dropCycle(edges);
        return 0;
    }
}