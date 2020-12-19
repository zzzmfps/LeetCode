# 24ms, 85.37%; 12.6MB, 100.00%
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        x, y = 1, 0
        for v in str(n):
            x, y = x * int(v), y + int(v)
        return x - y
    
