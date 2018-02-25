# 47ms, 44.13%
class Solution(object):
    def titleToNumber(self, s):
        res = 0
        for c in s:
            res = res * 26 + ord(c) - 64    # - 64 = - ord('A') + 1
        return res
        
