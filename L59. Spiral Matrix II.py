class Solution:
    def generateMatrix(self, n: int) -> list[list[int]]:
        row_top = 0
        col_l = 0
        row_btm = n-1
        col_r = n-1
        temp = 1
        res = [[0]*n for _ in range(n)]
        while(row_top<row_btm):
            for j in range(col_l, col_r+1):
                res[row_top][j] = temp
                temp += 1
            for i in range(row_top, row_btm+1):
                res[i][col_r] = temp
                temp += 1
            for j in range(col_r, col_l-1, -1):
                res[row_btm][j] = temp
                temp += 1
            for i in range(row_btm, row_top-1, -1):
                res[i][col_l] = temp
                temp += 1
            row_top += 1
            row_btm -= 1
            col_l += 1
            col_r -= 1
        
        if (n % 2):
            res[n//2][n//2] = temp
        return res


if __name__ == "__main__":
    n = 3  
    res = Solution().generateMatrix(n)
    for row in res:
        print(row)
