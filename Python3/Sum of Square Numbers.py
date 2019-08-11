# 272ms, 52.44%; 14.2MB, 50.00%
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        for i in range(0, 1 + int((c // 2) ** 0.5)):
            tmp = c - i ** 2
            if tmp == int(tmp ** 0.5) ** 2: return True
        return False
