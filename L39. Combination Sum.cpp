#include "data_structures/structures.hpp"

class Solution {
public:
    vector<vector<int>> res;
    void backTrack(vector<int>& candidates, int target, vector<int>& path, int start){
        if(target == 0){
            res.push_back(path);
            return;
        }
        for(int i=start; i<candidates.size(); ++i){
            if(candidates[i]>target) break;
            path.push_back(candidates[i]);
            backTrack(candidates, target-candidates[i], path, i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backTrack(candidates, target, path, 0);
        return res;
    }
};