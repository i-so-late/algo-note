/*https://kamacoder.com/problempage.php?pid=1181*/

#include "data_structures/structures.hpp"

class AdjacentList{
    vector<int> father;
public:
    AdjacentList(){
        father = vector<int>(1001, 0);
    }

    void init(int n){
        for(int i=0; i<=n; ++i){
            father[i] = i;
        }
    }
    int find(int u){
        return u==father[u]? u : father[u] = find(father[u]);
    }
    int isSame(int u, int v){
        u = find(u);
        v = find(v);
        return u==v;
    }
    void join(int u, int v){
        u = find(u);
        v = find(v);
        if (u==v) return ;
        father[v] = u;
    }
};

int main(){
    int n;
    cin >> n;
    AdjacentList adj;
    adj.init(n);
    for(int i=0; i<n; ++i){
        int a,b;
        cin >> a >> b;
        if(adj.isSame(a, b)){
            cout << a << ' ' << b << endl;
            return 0; 
        }
        adj.join(a, b);
    }
    return 0;
}