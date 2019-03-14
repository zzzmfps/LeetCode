# 76ms, 53.82%; 13.5MB, 6.10%
class Solution:
    def minFallingPathSum(self, A: list) -> int:
        dp, row, col = A[0][:], len(A), len(A[0])
        for i in range(1, row):
            last = 100
            for j in range(col):
                dp[j], last = A[i][j] + min(last, dp[j], dp[min(j + 1, col - 1)]), dp[j]
        return min(dp)
