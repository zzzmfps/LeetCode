# 100ms, 57.48%; 20MB, 5.00%
class Solution:
    def countBits(self, num: int) -> list:
        res = [0 for _ in range(num + 1)]
        for i in range(1, num + 1):
            if res[i]: continue
            res[i] = bin(i).count('1')
            j = i << 1
            while j <= num:
                res[j] = res[i]
                j <<= 1
        return res
