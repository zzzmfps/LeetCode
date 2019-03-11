# 64ms, 52.42%; 13.6MB, 5.45%
class Solution:
    def transpose(self, A: list) -> list:
        return [[A[j][i] for j in range(len(A))] for i in range(len(A[0]))]
