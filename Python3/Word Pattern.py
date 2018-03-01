# 36ms, 100.0%
class Solution:
    def wordPattern(self, pattern, strs):
        p, s = pattern, strs.split()
        return len(p) == len(s) and len(set(zip(p, s))) == len(set(p)) == len(set(s))
        
