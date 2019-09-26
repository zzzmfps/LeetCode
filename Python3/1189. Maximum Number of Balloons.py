# 40ms, 68.15%; 13.8MB, 100.00%
from collections import Counter

class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        instance, tmp = Counter('balloon'), Counter(text)
        res = len(text)
        for v in instance:
            res = min(res, tmp[v] // instance[v])
        return res
