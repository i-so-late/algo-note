#include "data_structures/structures.hpp"

class Solution {
public:

    int binarySearch(vector<int>& nums, int target, bool isLeft){
        int left = 0;
        int right = nums.size()-1;
        int res = -1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid] < target){
                left = mid+1;
            }else if(nums[mid] > target){
                right = mid-1;
            }else{
                res = mid;
                if(isLeft) right = mid - 1;
                else left = mid+1;
            }
        }
        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);
        return {left, right};
    }
};