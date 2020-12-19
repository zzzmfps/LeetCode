# 100ms, 100.0%
class Solution:
    def convert(self, s, numRows):
        if numRows == 1: return s
        index, is_down, res = 0, 1, [[] for i in range(numRows)]
        for i in range(len(s)):
            if index == 0: is_down = 1
            elif index == numRows - 1: is_down = -1
            res[index].append(s[i])
            index += is_down
        return ''.join([''.join(part) for part in res])
    
