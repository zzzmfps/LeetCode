# 44ms
class Solution:
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        size, last = len(S), -1
        res = []
        for i in range(size):
            if S[i] != C: continue
            if not res:
                res += list(range(i, -1, -1))
            else:
                res += list(range(1, (i - last + 1) // 2)) + list(range((i - last) // 2, -1, -1))
            last = i
        return res + list(range(1, size - last))
    
