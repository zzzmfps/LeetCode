# 36ms, 100.0%
class Solution:
    def uniquePaths(self, m, n):
        fac1, fac2 = m + n - 2, min(m, n) - 1
        res1 = res2 = 1
        for i in range(1, fac2 + 1):
            res1, res2 = res1 * fac1, res2 * i
            fac1 = fac1 - 1
        return res1 // res2
        
