# 56ms, 100.0%
class Solution:
    def titleToNumber(self, s):
        res = 0
        for c in s:
            res = res * 26 + ord(c) - 64    # - 64 = - ord('A') + 1
        return res
        
