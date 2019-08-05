# 36ms, 98.75%; 13.8MB, 6.56%
class Solution:
    def prisonAfterNDays(self, cells: list, N: int) -> list:
        N %= 14
        for _ in range(N if N else 14):
            tmp = [0] * 8
            for i in range(1, 7):
                tmp[i] = 1 if cells[i - 1] == cells[i + 1] else 0
            cells = tmp
        return cells
