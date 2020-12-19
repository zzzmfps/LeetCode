# 60ms, 100.0%
class Solution:
    def isUgly(self, num):
        if num == 0: return False
        ugly_factors = [2, 3, 5]
        for uf in ugly_factors:
            while num % uf == 0:
                num /= uf
        return True if num == 1 else False
    
