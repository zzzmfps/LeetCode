# 68ms, 58.20%
class Solution:
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        size = len(s)
        for i in range(1, size // 2 + 1):
            if size % i != 0: continue
            if s == s[:i] * (size // i): return True
        return False
    
