# 28ms, 75.06%
class Solution(object):
    def convertToTitle(self, n):
        res = ''
        while n:
            res = chr(ord('A') + (n - 1) % 26) + res    # chr: int-->char, ord: char-->int
            n = (n - 1) // 26
        return res
        
