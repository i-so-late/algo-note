#include "data_structures/structures.hpp"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> minDp(n, 0);
        vector<int> maxDp(n, 0);
        int res = nums[0];
        minDp[0] = nums[0]; maxDp[0] = nums[0];
        for(int i=1; i<nums.size(); ++i){
            minDp[i] = min(minDp[i-1]*nums[i], min(maxDp[i-1]*nums[i], nums[i]));
            maxDp[i] = max(minDp[i-1]*nums[i], max(maxDp[i-1]*nums[i], nums[i]));
            res = max(res, maxDp[i]);
        }
        return res;
    }
};