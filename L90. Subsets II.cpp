#include "data_structures/structures.hpp"

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backTrack(vector<int>& nums, int start){
        if(start >= nums.size()){
            return;
        }
        for(int i=start; i<nums.size(); ++i){
            if(i!=start && nums[i]==nums[i-1]){
                while(i<nums.size() && nums[i]==nums[i-1]) ++i;
                if(i==nums.size()) break;
            }
            path.push_back(nums[i]);
            res.push_back(path);
            backTrack(nums, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.push_back(path);
        sort(nums.begin(), nums.end());
        backTrack(nums, 0);
        return res;
    }
};