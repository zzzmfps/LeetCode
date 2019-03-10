# 36ms, 50.33%; 13.3MB, 5.77%
class Solution:
    def brokenCalc(self, X: int, Y: int) -> int:
        count = 0
        while X < Y:
            if Y & 1:
                Y += 1
            else:
                Y //= 1
            count += 1
        return count + X - Y
