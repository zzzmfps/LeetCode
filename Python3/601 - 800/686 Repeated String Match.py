# 40ms, 97.63%
class Solution:
    def repeatedStringMatch(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: int
        """
        lena, lenb, left = len(A), len(B), B.find(A)
        if left == -1 and lena * 2 - 2 < lenb or left >= lena: return -1
        if left == -1: return 1 if B in A else (2 if B in A * 2 else -1)
        num, right = (lenb - left) // lena, (lenb - left) % lena
        return min(1, left) + num + min(1, right) if A[lena - left:] + A * num + A[:right] == B else -1
    
