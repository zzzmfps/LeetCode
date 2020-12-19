# 472ms, 99.67%; 12.7MB, 100.00%
class Solution:
    def islandPerimeter(self, grid: [[int]]) -> int:
        ret = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if not grid[i][j]: continue
                ret += 4
                if i and grid[i - 1][j]: ret -= 2
                if j and grid[i][j - 1]: ret -= 2
        return ret
