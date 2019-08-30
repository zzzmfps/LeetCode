# 60ms, 71.91%; 14MB, 6.00%
class Solution:
    def flipAndInvertImage(self, A: list) -> list:
        for i in range(len(A)):
            A[i] = [x ^ 1 for x in reversed(A[i])]
        return A
