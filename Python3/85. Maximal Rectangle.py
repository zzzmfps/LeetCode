# 216ms, 82.08%; 15MB, 6.25%
class Solution:
    def maximalRectangle(self, matrix: list) -> int:
        if not matrix: return 0
        row, col = len(matrix), len(matrix[0])
        // the consecutive '1's begin at index left[j] and end at index right[j](not included)
        left, right, height = [0] * col, [col] * col, [0] * col
        res = 0
        for i in range(row):
            cur_left, cur_right = 0, col
            for j in range(col):
                if matrix[i][j] == '1':
                    left[j] = max(left[j], cur_left)
                    height[j] += 1
                else:
                    left[j] = height[j] = 0
                    cur_left = j + 1
            for j in range(col - 1, -1, -1):
                if matrix[i][j] == '1':
                    right[j] = min(right[j], cur_right)
                    res = max(res, height[j] * (right[j] - left[j]))
                else:
                    right[j] = col
                    cur_right = j
        return res
