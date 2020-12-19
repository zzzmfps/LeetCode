# 72ms, 61.79%
class Solution:
    def licenseKeyFormatting(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        res, s = [], s.upper()
        rev, count = len(s) - 1, 0
        while rev >= 0:
            if s[rev] != '-':
                if count == k:
                    res.append('-')
                    count = 0
                res.append(s[rev])
                count += 1
            rev -= 1
        return ''.join(res[::-1])
    
