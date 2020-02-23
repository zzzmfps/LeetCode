# 156ms, 96.57%; 12.7MB, 100.00%
class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        col, k = len(grid[0]), k % (len(grid) * len(grid[0]))
        res = [val for row in grid for val in row]
        res = res[-k:] + res[:-k]
        res = [res[i:i + col] for i in range(0, len(res), col)]
        return res
