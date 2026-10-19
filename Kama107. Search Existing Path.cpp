/*https://kamacoder.com/problempage.php?pid=1179*/

#include "data_structures/structures.hpp"

class Solution{
public:
    vector<int> father;

    int find(int u){
        return u==father[u]? u : father[u] = find(father[u]);
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

    bool searchExistingPath(int src, int des){
        return isSame(src, des);
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    Solution s;
    for(int i=0; i<n; ++i){
        s.father.push_back(i);
    }
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        s.join(a-1, b-1);
    }
    int src, des;
    cin >> src >> des;
    if(s.searchExistingPath(src-1, des-1)) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}