# 424ms
class Solution:
    def hitBricks(self, grid, hits):
        def dfs(i, j):
            if not (0 <= i < m and 0 <= j < n) or grid[i][j] != 1: return 0
            grid[i][j] = 2
            return 1 + sum(dfs(x, y) \
                           for x, y in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)])
        
        def is_connected(i, j):
            return i == 0 or any([0 <= x < m and 0 <= y < n and grid[x][y] == 2 \
                                  for x, y in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]])
        
        m, n = len(grid), len(grid[0])
        for i, j in hits:
            grid[i][j] -= 1
        for j in range(n):
            dfs(0, j)
        res = [0] * len(hits)
        for k in reversed(range(len(hits))):
            i, j = hits[k]
            grid[i][j] += 1
            if grid[i][j] == 1 and is_connected(i, j): res[k] = dfs(i, j) - 1
            
        return res
    
