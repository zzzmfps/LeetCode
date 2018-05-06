# 36ms, 96.63%
class Solution:
    def rotateString(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        if A == B: return True
        beg, list_a = B[0], list(A)
        for i in range(len(A)):
            if beg != A[i]: continue
            if B == ''.join(list_a[i:] + list_a[:i]): return True
        return False
