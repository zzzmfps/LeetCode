# 300ms, 41.41%; 16.2MB, 100.00%
class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> list:
        tmp = []
        for r in range(R):
            for c in range(C):
                tmp.append((abs(r - r0) + abs(c - c0), [r, c]))
        tmp.sort(key=lambda x: x[0])
        return [x[1] for x in tmp]
