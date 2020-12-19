# 40ms, 92.28%
class Solution:
    def isPerfectSquare(self, num):
        x = num
        while x * x > num:
            x = (x + num // x) // 2
        return x * x == num
    
