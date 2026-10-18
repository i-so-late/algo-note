/*https://kamacoder.com/problempage.php?pid=1177*/

#include "data_structures/structures.hpp"

struct AdjNode
{
    int val;
    AdjNode* next;
    AdjNode(int s){this->val = s; next = nullptr;}
};

class Solution{
    unordered_map<int, AdjNode*> adjlist;
public:
    int bfs(int begin){
        queue<int> que;
        unordered_set<int> us;
        que.push(begin);
        us.emplace(begin);
        while(!que.empty()){
            int n = que.size();
            while(n){
                int cur = que.front();
                que.pop();
                AdjNode* tmp = adjlist[cur];
                while(tmp){
                    if(us.find(tmp->val)==us.end()){
                        que.push(tmp->val);
                        us.emplace(tmp->val);
                    }
                    tmp = tmp->next;
                }
                n--;
            }
        }
        return us.size();
    }

    int directedGraphConnectivity(unordered_map<int, AdjNode*> adj, int n){
        this->adjlist = adj;
        if(bfs(1) == n) return 1;
        return -1;
    }
};

int main(){
    int n, edge;
    cin >> n >> edge;
    unordered_map<int, AdjNode*> adjlist;
    for(int i=0; i<edge; ++i){
        int a,b;
        cin >> a >> b;
        if(adjlist.count(a)){
            AdjNode* tmp = adjlist[a];
            while(tmp->next) tmp = tmp->next;
            tmp->next = new AdjNode(b);
        }else{
            adjlist[a] = new AdjNode(b);
        }
    }
    Solution s;
    cout << s.directedGraphConnectivity(adjlist, n) << endl;
    return 0;
}