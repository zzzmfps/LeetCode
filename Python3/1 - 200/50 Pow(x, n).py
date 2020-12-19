# 48ms, 66.48%
class Solution:
    def myPow(self, x, n):
        res, abs_n = 1, abs(n)
        while abs_n:
            tmp_res, tmp_n = x, 1
            while tmp_n * 2 < abs_n:
                tmp_res *= tmp_res
                tmp_n *= 2
            res *= tmp_res
            abs_n -= tmp_n
        return res if n > 0 else 1 / res
    
