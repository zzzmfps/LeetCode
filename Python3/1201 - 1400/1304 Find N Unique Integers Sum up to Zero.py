# 32ms, 61.76%; 12.6MB, 100.00%
class Solution:
    def sumZero(self, n: int) -> List[int]:
        res = list(range(-(n >> 1), 1 + (n >> 1)))
        if not n & 1: res[n - 1] += res.pop()
        return res
