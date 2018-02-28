# 44ms, 100.0%
class Solution:
    def isAnagram(self, s, t):
        if len(s) != len(t): return False
        s_set, t_set = set(s), set(t)
        if len(s_set) != len(t_set): return False
        for c in s_set:
            if s.count(c) != t.count(c): return False
        return True
    
