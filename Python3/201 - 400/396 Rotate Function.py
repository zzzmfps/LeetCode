# 88ms, 18.52%
class Solution:
    def maxRotateFunction(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        res, sums, size = 0, sum(A), len(A)
        for i in range(size):
            res += i * A[i]
        tmp = res
        for i in range(size - 1):
            tmp = tmp - sums + size * A[i]
            res = max(res, tmp)
        return res
