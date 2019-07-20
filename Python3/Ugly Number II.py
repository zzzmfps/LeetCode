# 136ms, 88.53%; 13.9MB, 5.29%
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        res = [1] * n
        t1, t2, t3 = 0, 0, 0
        for i in range(1, n):
            r1, r2, r3 = 2 * res[t1], 3 * res[t2], 5 * res[t3]
            res[i] = min(r1, r2, r3)
            if res[i] == r1: t1 += 1
            if res[i] == r2: t2 += 1
            if res[i] == r3: t3 += 1
        return res[-1]
