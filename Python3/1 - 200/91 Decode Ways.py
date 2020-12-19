# 44ms, 96.21%
class Solution:
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s or s[0] == '0': return 0
        r1, r2, size = 1, 1, len(s)
        for i in range(1, size):
            if s[i] == '0': r1 = 0
            if s[i - 1] == '1' or s[i - 1] == '2' and s[i] <= '6':
                r1, r2 = r1 + r2, r1
            else:
                r2 = r1
        return r1 
    
