# 52ms, 93.98%
class Solution:
    def largeGroupPositions(self, S):
        """
        :type S: str
        :rtype: List[List[int]]
        """
        i, j, lens, res = 0, 0, len(S), []
        while i + 2 < lens:
            while j + 1 < lens and S[j + 1] == S[j]:
                j += 1
            if j - i > 1: res.append([i, j])
            i = j = j + 1
        return res
    
