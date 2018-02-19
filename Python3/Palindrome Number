# 260ms, 100.0%
class Solution:
    def isPalindrome(self, x):
        if x < 0:
            return False
        res, ori = 0, x
        while x:
            res = res * 10 + x % 10
            x //= 10
        return res == ori
        
