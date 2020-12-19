# 52ms, 94.38%; 13.9MB, 11.11%
class Solution:
    def largestSumAfterKNegations(self, A: list, K: int) -> int:
        res, neg0 = sum(A), [x for x in A if x <= 0]
        res -= 2 * sum(sorted(neg0)[:K])
        x = K - len(neg0)
        if x > 0 and x & 1: res -= 2 * abs(min(A, key=abs))
        return res
    
