#include "data_structures/structures.hpp"

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backTrack(vector<int>& nums, vector<bool>& used){
        if(path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        int uset[21] = {0};
        for(int i=0; i<nums.size(); ++i){
            if(used[i]) continue;
            if(uset[nums[i]+10]) continue;
            uset[nums[i]+10] = 1;
            path.push_back(nums[i]);
            used[i] = true;
            backTrack(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backTrack(nums, used);
        return res;
    }
};