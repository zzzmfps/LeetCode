# 44ms, 88.01%
class Solution:
    def findTheDifference(self, s, t):
        check = 0
        for ss in s: check ^= ord(ss)
        for tt in t: check ^= ord(tt)
        return chr(check)
    
