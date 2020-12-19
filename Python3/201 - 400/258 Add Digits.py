# 60ms, 100.0%
class Solution:
    def addDigits(self, num):
        return (num - 1) % 9 + 1 if num > 0 else 0
        
