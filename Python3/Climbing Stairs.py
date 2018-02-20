# 40ms, 100.0%
class Solution:
    def climbStairs(self, n):
        pre = nxt = 1
        for _ in range(1, n):
            pre, nxt = nxt, pre + nxt
        return nxt
        
