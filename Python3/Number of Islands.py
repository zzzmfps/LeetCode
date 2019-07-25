# 132ms, 99.35%; 15.1MB, 20.60%
class Solution:
    def numIslands(self, grid: list) -> int:
        res = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] != '1': continue
                res += 1
                self.visit(grid, i, j)
        return res

    def visit(self, grid: list, i: int, j: int) -> None:
        grid[i][j] = '2'
        if i > 0 and grid[i - 1][j] == '1': self.visit(grid, i - 1, j)
        if j > 0 and grid[i][j - 1] == '1': self.visit(grid, i, j - 1)
        if i + 1 < len(grid) and grid[i + 1][j] == '1': self.visit(grid, i + 1, j)
        if j + 1 < len(grid[0]) and grid[i][j + 1] == '1': self.visit(grid, i, j + 1)
        
