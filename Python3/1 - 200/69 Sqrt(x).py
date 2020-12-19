# 64ms, 100.0%
class Solution:
    def mySqrt(self, x):
        r = x
        while r * r > x:
            r = (r + x // r) // 2
        return int(r)
