/*https://kamacoder.com/problempage.php?pid=1053*/

#include "data_structures/structures.hpp"

/*
// prim algorithm
int main(){
    int v, e;
    cin >> v >> e;
    int a, b, c;
    vector<vector<int>> grid(v+1, vector<int>(v+1, 10001));
    for(int i=0; i<e; ++i){
        cin >> a >> b >> c;
        grid[a][b] = c;
        grid[b][a] = c;
    }

    vector<int> minDist(v+1, 10001);
    vector<bool> isInTree(v+1, false);

    for(int i=1; i<v; ++i){
        int minD = INT_MAX;
        int cur = 0;
        for(int j=1; j<=v; ++j){
            if(!isInTree[j] && minDist[j] < minD){
                minD = minDist[j];
                cur = j;
            }
        }

        isInTree[cur] = true;

        for(int j=1; j<=v; ++j){
            if(!isInTree[j] && minDist[j] > grid[cur][j]){
                minDist[j] = grid[cur][j];
            }
        }
    }

    int res = 0;
    for(int i = 2; i<=v; ++i){
        res += minDist[i];
    }
    cout << res << endl;
    return 0;
}
*/


//Kruskal

struct Edge{
    int l, r, v;
    Edge(int a, int b, int c) : l(a), r(b), v(c) {}
};

vector<int> father(10001, 0);

void init(int n){
    for(int i=1; i<=n; ++i) father[i] = i;
}

int find(int u){
    return u==father[u]? u : father[u] = find(father[u]);
}

void join(int u, int v){
    u = find(u);
    v = find(v);
    if (u == v) return;
    father[v] = u;
}

bool isSame(int u, int v){
    u = find(u);
    v = find(v);
    return u==v;
}

int main(){
    int v, e;
    cin >> v >> e;
    int a, b, c;
    vector<Edge> edges;
    for(int i=0; i<e; ++i){
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){ return a.v < b.v; });

    init(v);
    int res = 0;
    for(int i=0; i<edges.size(); ++i){
        const Edge& cur = edges[i];
        if(isSame(cur.l, cur.r)) continue;
        join(cur.l, cur.r);
        res += cur.v;
    }
    cout << res << endl;
    return 0;
}