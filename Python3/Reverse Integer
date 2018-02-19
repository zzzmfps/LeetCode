# 48ms, 100.0%
class Solution:
    def reverse(self, x):
        sign = -1 if x < 0 else 1
        x = sign * x
        res = 0
        while x:
            res = res * 10 + x % 10
            x = x // 10
        res = sign * res
        return res if res >= -2 ** 31 and res < 2 ** 31 else 0
        
