#include "data_structures/structures.hpp"

class Solution {
public:
    int subSum = 0;
    bool backTrack(vector<int>& nums, vector<bool>& rec, int k, int rest, int start) {
        if (k == 1) return true;
        if (rest == 0) return backTrack(nums, rec, k - 1, subSum, 0);
        for (int i = start; i < nums.size(); ++i) {
            if (rec[i] || nums[i] > rest) continue;
            rec[i] = true;
            if (backTrack(nums, rec, k, rest - nums[i], i + 1)) return true;
            rec[i] = false;

            if (rest == subSum) return false;   // 剪枝 1：空桶放第一个可用的数都失败，无解
            if (rest == nums[i]) return false;  // 剪枝 2：恰好填满这个桶都失败，无解
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) ++i;  // 剪枝 3：跳过相同的值
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (auto p : nums) sum += p;
        if (sum % k != 0) return false;
        subSum = sum / k;
        sort(nums.rbegin(), nums.rend());        // 改成从大到小
        if (nums[0] > subSum) return false;
        vector<bool> rec(nums.size(), false);
        return backTrack(nums, rec, k, subSum, 0);
    }
};