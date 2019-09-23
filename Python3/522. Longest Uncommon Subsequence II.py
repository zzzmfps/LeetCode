# 44ms, 45.45%; 13.7MB, 100.00%
class Solution:
    def findLUSlength(self, strs: list) -> int:
        for s in sorted(strs, key=len, reverse=True):
            if sum(self.helper(s, t) for t in strs if len(s) <= len(t)) == 1:
                return len(s)
        return -1

    def helper(self, s: list, t: list) -> bool:
        t = iter(t)
        return all(c in t for c in s)
