# 96ms, 86.60%; 17.2MB, 100.0%
class Solution:
    def isMonotonic(self, A: 'List[int]') -> 'bool':
        B = sorted(A)
        return B == A or B == A[::-1]
