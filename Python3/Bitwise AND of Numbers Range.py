# 384ms, 31.37%
class Solution:
    def rangeBitwiseAnd(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        diff, ret = n - m, 0
        for i in range(31):
            exp = 2 ** i
            if m < exp: break
            if diff < exp and (m & exp) and (n & exp): ret += exp
        return ret
