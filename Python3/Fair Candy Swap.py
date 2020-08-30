# 412ms, 97.38%; 16.1MB, 8.33%
class Solution:
    def fairCandySwap(self, A: list, B: list) -> list:
        diff = (sum(A) - sum(B)) >> 1
        set_A = set(A)
        for b in B:
            if b + diff in set_A: return [b + diff, b]
