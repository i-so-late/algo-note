#include "data_structures/structures.hpp"

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0; int right = -1;
        int n = nums.size(); int res = n + 1;
        int sum = 0;
        while(right < n){
            if(sum < target){
                right++;
                if (right == n) break;
                sum += nums[right];
            }else{
                sum -= nums[left];
                left++;
            }
            if (sum >= target){
                res = min(res, right-left+1);
            }
        }
        return res == n+1 ? 0 : res;
    }
};