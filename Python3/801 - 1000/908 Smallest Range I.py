# 44ms, 74.02%; 14.1MB, 8.33%
class Solution:
    def smallestRangeI(self, A: list, K: int) -> int:
        _min, _max = min(A), max(A)
        tmp = _max - _min - 2 * K
        return 0 if tmp <= 0 else tmp
