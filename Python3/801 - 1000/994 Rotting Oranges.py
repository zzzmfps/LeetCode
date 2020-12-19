# 52ms, 60.92%; 13.1MB, 5.12%
class Solution:
    def orangesRotting(self, grid: list) -> int:
        time, row, col = 0, len(grid), len(grid[0])
        rotten = [(i, j) for i in range(row) for j in range(col) if grid[i][j] == 2]
        while True:
            nxt = []
            while rotten:
                i, j = rotten.pop()
                if i - 1 >= 0: self.__helper(i - 1, j, grid, nxt)
                if j - 1 >= 0: self.__helper(i, j - 1, grid, nxt)
                if i + 1 < row: self.__helper(i + 1, j, grid, nxt)
                if j + 1 < col: self.__helper(i, j + 1, grid, nxt)
            if not nxt: break
            rotten = nxt
            time += 1
        return -1 if sum([g.count(1) for g in grid]) else time

    def __helper(self, i, j, grid: list, nxt: list) -> None:
        if grid[i][j] == 1:
            grid[i][j] = 2
            nxt.append((i, j))
