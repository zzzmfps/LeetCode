# 188ms, 91.51%; 13.7MB, 100.00%
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix: return 0
        row, col, length = len(matrix), len(matrix[0]), self.__helper(matrix)
        dp1, dp2 = [1 if x == '1' else 0 for x in matrix[0]], [0] * col
        for i in range(1, row):
            dp2[0] = 1 if matrix[i][0] == '1' else 0
            for j in range(1, col):
                if matrix[i][j] == '0': continue
                dp2[j] = 1 + min(dp1[j - 1], dp1[j], dp2[j - 1])
                length = max(length, dp2[j])
            dp1, dp2 = dp2, [0] * col
        return length**2

    def __helper(self, matrix: List[List[str]]) -> int:
        for x in matrix[0]:
            if x == '1': return 1
        for i in range(1, len(matrix)):
            if matrix[i][0] == '1': return 1
        return 0
