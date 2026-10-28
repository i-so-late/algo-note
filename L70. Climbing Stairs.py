class Solution:
    def climbStairs(self, n: int) -> int:
        a1 = 1
        a2 = 2
        if n == 1:
            return a1
        if n == 2:
            return a2
        for i in range(3, n+1):
            tmp = a2
            a2 = a1+a2
            a1 = tmp
        return a2
