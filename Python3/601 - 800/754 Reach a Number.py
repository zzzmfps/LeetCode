# 36ms, 92.28%; 12.9MB, 7.14%
class Solution:
    def reachNumber(self, target: int) -> int:
        target = abs(target)
        n = int((1 + (1 + 8 * target) ** 0.5) / 2) - 1
        acc = n * (n + 1) // 2
        while acc < target or (acc - target) & 1:
            n += 1
            acc += n
        return n
