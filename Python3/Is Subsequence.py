# 40ms, 95.81%; 18.4MB, 26.67%
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        idx = 0
        for c in s:
            tmp = t.find(c, idx)
            if tmp == -1: return False
            idx = tmp + 1
        return True
