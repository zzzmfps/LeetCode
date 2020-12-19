# 24ms, 96.07%; 13.9MB, 36.25%
class Solution:
    def bulbSwitch(self, n: int) -> int:
        m, count = 1, 0
        while m * m <= n:
            m += 1
            count += 1
        return count
