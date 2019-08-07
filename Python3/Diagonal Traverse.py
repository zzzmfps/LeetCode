# 220ms, 78.65%; 16.4MB, 7.69%
class Solution:
    def findDiagonalOrder(self, matrix: list) -> list:
        if not matrix: return []
        res = []
        row, col = len(matrix), len(matrix[0])
        i, j, delta = 0, 0, -1
        for _ in range(row + col - 1):
            while 0 <= i < row and 0 <= j < col:
                res.append(matrix[i][j])
                i, j = i + delta, j - delta
            if delta < 0:
                i += 1
                if j == col:
                    i += 1
                    j -= 1
            else:
                j += 1
                if i == row:
                    j += 1
                    i -= 1
            delta = -delta
        return res
