# 40ms, 97.75%
class Solution:
    def numTilings(self, n):
        """
        :type N: int
        :rtype: int
        """
        res = [1, 1, 2]
        for _ in range(n - 2):
            res[0], res[1], res[2] = res[1], res[2], res[2] * 2 + res[0]
        return res[2 if n > 1 else 1] % (10**9 + 7)
    
