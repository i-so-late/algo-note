class Solution:
    def coinChange(self, coins: list[int], amount: int) -> int:
        dp = [99999] * (amount+1)
        dp[0] = 0
        for j in range(1, amount+1):
            for i in range(len(coins)):
                if coins[i] > j:
                    continue
                else:
                    dp[j] = min(dp[j], dp[j-coins[i]]+1)
        return dp[-1] if dp[-1] != 99999 else -1
