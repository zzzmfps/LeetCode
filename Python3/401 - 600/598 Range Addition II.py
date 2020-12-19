# 40ms, 98.45%
class Solution:
    def maxCount(self, m, n, ops):
        """
        :type m: int
        :type n: int
        :type ops: List[List[int]]
        :rtype: int
        """
        if not ops: return m * n
        (min_a, min_b) = ops[0]
        for (a, b) in ops:
            if a < min_a: min_a = a
            if b < min_b: min_b = b
        return min_a * min_b
    
