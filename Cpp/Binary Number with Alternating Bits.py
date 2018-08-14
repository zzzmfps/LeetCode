# 36ms, 100.0%
class Solution:
    def hasAlternatingBits(self, n):
        """
        :type n: int
        :rtype: bool
        """
        curMax = 2**int(math.log2(n) + 1)
        while n > 1:
            n = curMax - n - 1
            curMax >>= 1
        return n == 1 and curMax == 2
    
