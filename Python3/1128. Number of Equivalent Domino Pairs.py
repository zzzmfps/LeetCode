# 260ms, 98.14%; 23.3MB, 100.00%
from collections import Counter

class Solution:
    def numEquivDominoPairs(self, dominoes: list) -> int:
        tmp = Counter((x, y) if x < y else (y, x) for x, y in dominoes)
        res = 0
        for freq in tmp.values():
            res += freq * (freq - 1) >> 1
        return res
