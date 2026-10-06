#include "data_structures/structures.hpp"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]>target && nums[i] >= 0) return res;
            for(int j=i+1; j<nums.size(); j++){
                long long sub = (long long)target - nums[i] - nums[j];
                int left = j+1, right = nums.size()-1;
                while(left<right){
                    if((long long)nums[left]+nums[right]>sub) right--;
                    else if((long long)nums[left]+nums[right]<sub) left++;
                    else{
                        res.push_back({nums[i],nums[j],nums[left],nums[right]});
                        while(left<right && nums[left]==nums[left+1]) left++;
                        while(left<right && nums[right]== nums[right-1]) right--;
                        left++;right--;
                    }
                }
                while(j<nums.size()-1 && nums[j]==nums[j+1]){
                    j++;
                }
            }
            while(i<nums.size()-2 && nums[i]==nums[i+1]){
                i++;
            }
        }
        return res;
    }
};