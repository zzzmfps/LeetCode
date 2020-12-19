# 36ms, 100.0%
class Solution:
    def convertToTitle(self, n):
        res = ''
        while n:
            res = chr(ord('A') + (n - 1) % 26) + res    # chr: int-->char, ord: char-->int
            n = (n - 1) // 26
        return res
        
