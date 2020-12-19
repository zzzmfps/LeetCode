# 24ms, 90.78%; 12.7MB, 100.00%
class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> list:
        a, b, c = sorted([a, b, c])
        diff1, diff2, diff3 = b - a, c - b, c - a - 2
        left = (0 if diff3 == 0 else 1 if diff1 < 3 or diff2 < 3 else 2)
        return [left, diff3]
