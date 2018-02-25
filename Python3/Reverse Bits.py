# 38ms, 54.34%
class Solution:
    def reverseBits(self, n):
        res = 0
        for _ in range(32):
            res = (res << 1) + (n & 1)    # precedence(high-->low): +, <<, & 
            n >>= 1
        return res
    
