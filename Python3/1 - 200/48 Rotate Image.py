# 48ms, 60.17%
class Solution:
    def rotate(self, matrix):
        n = len(matrix)
        r = n // 2
        for i in range(r):
            for j in range(n - 1 - 2 * i):
                tmp = matrix[i][i + j]
                matrix[i][i + j] = matrix[n - i - j - 1][i]
                matrix[n - i - j - 1][i] = matrix[n - i - 1][n - i - j - 1]
                matrix[n - i - 1][n - i - j - 1] = matrix[i + j][n - i - 1]
                matrix[i + j][n - i - 1] = tmp
        
