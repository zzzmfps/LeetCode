# 236ms, 99.48%
from collections import Counter


class Solution:
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        A, B, C, D = Counter(A), Counter(B), Counter(C), Counter(D)
        AB, result = {}, 0
        for a, a_count in A.items():
            for b, b_count in B.items():
                AB[a + b] = AB.get(a + b, 0) + a_count * b_count
        for c, c_count in C.items():
            for d, d_count in D.items():
                count = AB.get(-c - d, 0)
                if count: result += count * c_count * d_count
        return result
    
