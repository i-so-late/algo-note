class Solution:

    def wordBreak(self, s: str, wordDict: list[str]) -> bool:
        dp = [False] * (len(s) + 1)
        dp[0] = True
        for i in range(1, len(s) + 1):
            for wd in wordDict:
                if len(wd) > i:
                    continue
                elif wd == s[i - len(wd):i] and dp[i - len(wd)]:
                    dp[i] = True
                    break

        return dp[-1]
