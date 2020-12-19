# 40ms, 69.15%; 13.2MB, 7.69%
class Solution:
    cw1 = '438167294381672'
    cw2 = '492761834927618'

    def numMagicSquaresInside(self, grid: list) -> int:
        row, col = len(grid), len(grid[0])
        if row < 3 or col < 3: return 0
        res = 0
        for i in range(2, row):
            for j in range(2, col):
                if grid[i - 1][j - 1] == 5 and self.__check(grid, i, j): res += 1
        return res

    def __check(self, grid: list, i: int, j: int) -> bool:
        tmp = grid[i][j - 2:j + 1][::-1] + [grid[i - 1][j - 2]] + grid[i - 2][j - 2:j + 1] + [grid[i - 1][j]]
        tmp = ''.join(str(x) for x in tmp)
        return tmp in self.cw1 or tmp in self.cw2
