class Solution:
    def lengthOfLIS(self, nums: list[int]) -> int:
        dp = [0]*(len(nums)+1)
        res = 0
        for i in range(1, len(nums)+1):
            j = i-1
            tmp = 0
            while (j > 0):
                if nums[j-1] < nums[i-1]:
                    tmp = max(tmp, dp[j])
                j -= 1
            dp[i] = tmp + 1
            res = max(dp[i], res)
        return res
