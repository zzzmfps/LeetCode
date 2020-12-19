# 60ms, 100.0%
class Solution:
    def isPowerOfFour(self, num):
        return num > 0 and not num & (num - 1) and not num & 0xAAAAAAAA
        
