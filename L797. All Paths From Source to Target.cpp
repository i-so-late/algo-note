#include "data_structures/structures.hpp"

class Solution {
public:
    void dfs(const vector<vector<int>>& graph, int target, int source){
        if(source == target){
            res.push_back(path);
            return;
        }
        for(int i=0; i<graph[source].size(); ++i){
            path.push_back(graph[source][i]);
            dfs(graph, target, graph[source][i]);
            path.pop_back();
        }
        return ;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph, graph.size()-1, 0);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> path;
};