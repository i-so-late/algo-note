#include <data_structures/structures>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int n = nums.size()-1;
        return max(rob1(nums, 0, n-1), rob1(nums, 1, n));
    };
    int rob1(vector<int>& nums, int begin, int end){
        if(begin == end) return nums[begin];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]); 
        for(int i=2; i< nums.size(); ++i){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp.back();
    }
};