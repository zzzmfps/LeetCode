# 124ms, 100.00%; 15MB, 26.32%
class Solution:
    def largestIsland(self, grid: list) -> int:
        if not grid: return 0
        id = 2
        area = {0: 0}
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] != 1: continue
                area[id] = self.visit(grid, i, j, id)
                id += 1
        max_area = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] != 0: continue
                tmp = set()
                if i > 0: tmp.add(grid[i - 1][j])
                if j > 0: tmp.add(grid[i][j - 1])
                if i + 1 < len(grid): tmp.add(grid[i + 1][j])
                if j + 1 < len(grid[0]): tmp.add(grid[i][j + 1])
                max_area = max(max_area, 1 + sum([area[x] for x in tmp]))
        return max_area if max_area else len(grid) * len(grid[0])

    def visit(self, grid, i, j, id) -> int:
        ret, grid[i][j] = 1, id
        if i > 0 and grid[i - 1][j] == 1: ret += self.visit(grid, i - 1, j, id)
        if j > 0 and grid[i][j - 1] == 1: ret += self.visit(grid, i, j - 1, id)
        if i + 1 < len(grid) and grid[i + 1][j] == 1: ret += self.visit(grid, i + 1, j, id)
        if j + 1 < len(grid[0]) and grid[i][j + 1] == 1: ret += self.visit(grid, i, j + 1, id)
        return ret
        
