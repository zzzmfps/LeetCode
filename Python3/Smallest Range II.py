# 100ms, 71.09%; 14.1MB, 5.26%
class Solution:
    def smallestRangeII(self, A: list, K: int) -> int:
        A.sort()
        _min, _max, ret = A[0], A[-1], A[-1] - A[0]
        for i in range(len(A) - 1):
            _min = min(A[i + 1], A[0] + 2 * K)
            _max = max(A[-1], A[i] + 2 * K)
            ret = min(ret, _max - _min)
        return ret
    
