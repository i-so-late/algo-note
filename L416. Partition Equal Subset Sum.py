class Solution:
    def canPartition(self, nums: list[int]) -> bool:
        n = sum(nums)
        if n % 2:
            return False
        n = n // 2
        dp = [0] * (n+1)
        for i in range(len(nums)):
            for j in range(n, nums[i]-1, -1):
                dp[j] = max(dp[j], dp[j-nums[i]]+nums[i])
        return True if dp[-1] == n else False
