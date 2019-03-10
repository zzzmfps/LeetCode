# 64ms, 79.96%; 17.3MB, 10.95%
class Solution:
    def kthSmallest(self, matrix: list, k: int) -> int:
        _min, _max, n = matrix[0][0], matrix[-1][-1], len(matrix)
        while _min < _max:
            mid, count = (_min + _max) // 2, 0
            for i in range(n):
                if matrix[i][0] > mid: continue
                l, r = 0, n - 1
                while l < r:
                    m = (l + r + 1) // 2
                    if matrix[i][m] <= mid:
                        l = m
                    else:
                        r = m - 1
                count += 1 + l
            if count < k:
                _min = mid + 1
            else:
                _max = mid
        return _min
