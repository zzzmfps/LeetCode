# 52ms, 69.06%; 13.2MB, 6.86%
class Solution:
    def isToeplitzMatrix(self, matrix: list) -> bool:
        m, n = len(matrix), len(matrix[0])
        for i in range(m):
            j, k = i + 1, 1
            while j < m and k < n:
                if matrix[j][k] != matrix[i][0]: return False
                j, k = j + 1, k + 1
        for i in range(1, n):
            j, k = 1, i + 1
            while j < m and k < n:
                if matrix[j][k] != matrix[0][i]: return False
                j, k = j + 1, k + 1
        return True
