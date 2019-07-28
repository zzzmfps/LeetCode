# 44ms, 92.31%; 14.4MB, 10.00%
class Solution:
    def __init__(self):
        self.record = {}

    def soupServings(self, N: int) -> float:
        if N > 4800: return 1.0
        return self.choice(N, N)

    def choice(self, A: int, B: int) -> float:
        if A <= 0 and B <= 0: return 0.5
        if A <= 0: return 1
        if B <= 0: return 0
        if (A - 100, B) not in self.record: self.record[(A - 100, B)] = self.choice(A - 100, B)
        if (A - 75, B - 25) not in self.record: self.record[(A - 75, B - 25)] = self.choice(A - 75, B - 25)
        if (A - 50, B - 50) not in self.record: self.record[(A - 50, B - 50)] = self.choice(A - 50, B - 50)
        if (A - 25, B - 75) not in self.record: self.record[(A - 25, B - 75)] = self.choice(A - 25, B - 75)
        self.record[(A, B)] = 0.25 * (self.record[(A - 100, B)] + self.record[(A - 75, B - 25)] + self.record[(A - 50, B - 50)] + self.record[(A - 25, B - 75)])
        return self.record[(A, B)]
