# 40ms, 100.0%
class Solution:
    def generate(self, numRows):
        res = [[1], [1, 1]]
        if numRows < 3: return res[: numRows]
        for _ in range(2, numRows):
            res.append([1, 1])
            for i in range(1, len(res[-2])):
                res[-1].insert(i, res[-2][i - 1] + res[-2][i])
        return res
    
