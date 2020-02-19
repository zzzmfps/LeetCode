# 104ms, 59.31%; 13.5MB, 100.00%
class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        row, col = len(nums), len(nums[0])
        if row * col != r * c: return nums
        ret, i, j = [[0] * c for _ in range(r)], 0, 0
        for x in nums:
            for y in x:
                ret[i][j] = y
                j += 1
                if j == c: i, j = i + 1, 0
        return ret
