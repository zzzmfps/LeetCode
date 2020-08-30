# 36ms, 74.22%; 13.8MB, 100.00%
class Solution:
    def __init__(self):
        self.d = {}

    def integerReplacement(self, n: int) -> int:
        if n == 1: return 0
        if n not in self.d:
            if n & 1:
                tmp = (n - 1) >> 1
                self.d[n] = 2 + min(self.integerReplacement(tmp), self.integerReplacement(tmp + 1))
            else:
                self.d[n] = 1 + self.integerReplacement(n >> 1)
        return self.d[n]
