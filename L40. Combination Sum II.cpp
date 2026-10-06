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
            if(i!=start && candidates[i]==candidates[i-1]){
                while(i<candidates.size() && candidates[i]==candidates[i-1]) ++i;
                if(i>=candidates.size()) return;
            }
            if(candidates[i]>target) break;
            path.push_back(candidates[i]);
            backTrack(candidates, target-candidates[i], path, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backTrack(candidates, target, path, 0);
        return res;
    }
};