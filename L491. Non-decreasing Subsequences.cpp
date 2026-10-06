#include "data_structures/structures.hpp"

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backTrack(vector<int>& nums, int start){
        if(path.size()>1)
            res.push_back(path);
        if(start >= nums.size()){
            return;
        }
        unordered_set<int> uset;
        for(int i=start; i<nums.size(); ++i){
            // if(i!=start && nums[i]==nums[i-1]){
            //     while(nums[i]==nums[i-1]) ++i;
            //     if(i==nums.size()) break;
            // }
            if(uset.find(nums[i])!=uset.end()) continue;
            uset.emplace(nums[i]);
            if(path.empty() || nums[i] >= path.back()){
                path.push_back(nums[i]);
                backTrack(nums, i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backTrack(nums, 0);
        return res;
    }
};