# 36ms, 75.00%
class Solution:
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        res, rn = 0, 1
        while n >= rn:
            left = n // rn // 10
            mid = n // rn % 10
            right = n % rn
            if mid == 0:
                res += left * rn
            elif mid == 1:
                res += left * rn + right + 1
            else:
                res += (left + 1) * rn
            rn *= 10
        return res
    
