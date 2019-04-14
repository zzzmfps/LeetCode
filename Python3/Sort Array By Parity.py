# 68ms, 82.03%; 13.6MB, 5.69%
class Solution:
    def sortArrayByParity(self, A: list) -> list:
        i, j = 0, len(A) - 1
        while i < j:
            a, b = A[i] & 1, A[j] & 1
            if a != b:
                if a == 1: A[i], A[j] = A[j], A[i]
                i += 1
                j -= 1
            elif a == 0:
                i += 1
            else:
                j -= 1
        return A
