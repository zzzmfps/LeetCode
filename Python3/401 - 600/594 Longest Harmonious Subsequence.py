# 404ms, 26.47%; 16.1MB, 7.69%
from collections import Counter


class Solution:
    def findLHS(self, nums: list) -> int:
        n = sorted(Counter(nums).items())
        res = 0
        for i in range(1, len(n)):
            if n[i - 1][0] + 1 < n[i][0]: continue
            res = max(res, n[i - 1][1] + n[i][1])
        return res
