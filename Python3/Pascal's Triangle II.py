# 32ms, 100.0%
class Solution:
    def getRow(self, rowIndex):
        res = []
        for i in range(-1, rowIndex):
            res.append(1)
            while i > 0:
                res[i] = res[i - 1] + res[i]
                i -= 1
        return res
    
