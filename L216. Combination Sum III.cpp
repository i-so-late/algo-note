#include "data_structures/structures.hpp"

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backTrack(int k, int sum, int start){
        if(path.size() == k){
            if(sum==0)
                res.push_back(path);
            return;
        }
        for(int i=start; i<=min(sum,9); ++i){
            path.push_back(i);
            backTrack(k,sum-i, ++start);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backTrack(k,n,1);
        return res;
    }
};