# 1316ms, 11.74%; 13.7MB, 100.00%
class Solution:
    def largest1BorderedSquare(self, grid: list) -> int:
        row, col = len(grid), len(grid[0])
        res = min(row, col)
        while res:
            for i in range(0, row - res + 1):
                for j in range(0, col - res + 1):
                    if self.check(grid, i, j, res): return res * res
            res -= 1
        return 0

    def check(self, grid: list, x: int, y: int, v: int) -> bool:
        if v == 1: return grid[x][y] == 1
        for _ in range(1, v):
            if grid[x][y] == 0: return False
            y += 1
        for _ in range(1, v):
            if grid[x][y] == 0: return False
            x += 1
        for _ in range(1, v):
            if grid[x][y] == 0: return False
            y -= 1
        for _ in range(1, v):
            if grid[x][y] == 0: return False
            x -= 1
        return True
