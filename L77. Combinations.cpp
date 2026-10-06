#include "data_structures/structures.hpp"

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backTrack(int n, int k, int start){
        if(path.size()==k){
            res.push_back(path);
            return;
        }
        for(int i=start; i<=n-(k-path.size())+1; ++i){
            path.push_back(i);
            backTrack(n, k, ++start);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        backTrack(n, k, 1);
        return res;
    }
};