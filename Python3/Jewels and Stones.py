// 36ms, 99.72%; 13MB, 5.25%
class Solution:
    def numJewelsInStones(self, j: str, s: str) -> int:
        res = 0
        for c in s:
            if c in j: res += 1
        return res
