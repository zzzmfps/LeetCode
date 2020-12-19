# 72ms, 98.08%; 14MB, 5.10%
class Solution:
    def largestPerimeter(self, A: list) -> int:
        A.sort(reverse=1)
        for i in range(2, len(A)):
            if A[i - 2] < A[i - 1] + A[i]: return  A[i - 2] + A[i - 1] + A[i]
        return 0
