# 64ms, 77.67%; 14.1MB, 7.69%
class Solution:
    def constructArray(self, n: int, k: int) -> list:
        res = [0] * n
        res[0:k:2] = [x for x in range(1, 1 + (1 + k) // 2)]
        res[1:k:2] = [x for x in range(n, n - k // 2, -1)]
        delta = -1 if k > 1 and res[k - 2] < res[k - 1] else 1
        for i in range(k, n):
            res[i] = res[i - 1] + delta
        return res
    
