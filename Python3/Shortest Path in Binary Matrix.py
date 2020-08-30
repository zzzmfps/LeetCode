# 772ms, 46.14%; 14MB, 100.00%
class Solution:
    def shortestPathBinaryMatrix(self, grid: list) -> int:
        if grid[0][0] or grid[-1][-1]: return -1
        grid[-1][-1] = -1
        row, col = len(grid), len(grid[0])
        count, stack = 1, [(0, 0)]
        while stack:
            for x, y in stack:
                grid[x][y] = count
            count += 1
            tmp = set()
            for x, y in stack:
                for x1, y1 in [(i, j) for i in [x - 1, x, x + 1] for j in [y - 1, y, y + 1]]:
                    if x1 < 0 or x1 == row or y1 < 0 or y1 == col or grid[x1][y1] > 0: continue
                    tmp.add((x1, y1))
            stack = list(tmp)
        return grid[-1][-1]
