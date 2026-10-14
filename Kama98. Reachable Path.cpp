/*
website: https://kamacoder.com/problempage.php?pid=1170
*/

#include "data_structures/structures.hpp"

class Solution{
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(const vector<vector<int>>& graph, int target, int source, vector<int>& rec){
        if(source == target){
            res.push_back(path);
            return;
        }
        for(int i=1; i<graph[source].size(); ++i){
            if(graph[source][i] == 0 || rec[i-1]==1) continue;
            rec[i-1] = 1;
            path.push_back(i);
            dfs(graph, target, i, rec);
            rec[i-1] = 0;
            path.pop_back();
        }
        return ;
    }
    void reachablePath(const vector<vector<int>>& graph, int target){
        vector<int> rec(target, 0);
        rec[0] = 1;
        path.push_back(1);
        dfs(graph, target, 1, rec);
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
    for(int i=0; i<m; ++i){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        graph[tmp1][tmp2] = 1;
    }
    Solution s;
    s.reachablePath(graph, n);
    auto res = s.res;
    if(res.empty()){
        cout<< -1 <<endl;
        return 0;
    }
    for(size_t i=0; i<res.size(); ++i){
        for(size_t j=0; j<res[i].size(); ++j){
            if(j==res[i].size()-1){
                cout << res[i][j];
            }
            else{
                cout << res[i][j] << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}