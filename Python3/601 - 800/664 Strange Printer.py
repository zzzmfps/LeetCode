# 396ms, 70.67%; 13.4MB, 33.33%
class Solution:
    def __init__(self):
        self.mat = [[0] * 100 for _ in range(100)]

    def strangePrinter(self, s: str) -> int:
        ss = []
        for c in s:
            if not ss or ss[-1] != c: ss.append(c)
        return self.dp(ss, 0, len(ss) - 1)

    def dp(self, s: str, l: int, r: int) -> int:
        if l > r or self.mat[l][r]: return self.mat[l][r]
        self.mat[l][r] = 1 + self.dp(s, l, r - 1)
        for i in range(l, r):
            if s[i] == s[r]:
                self.mat[l][r] = min(self.mat[l][r], self.dp(s, l, i) + self.dp(s, i + 1, r - 1))
        return self.mat[l][r]
