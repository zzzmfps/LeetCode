# 120ms, 96.70%
class Solution:
    def findAnagrams(self, s, p):
        len1, len2 = len(s), len(p)
        if len1 < len2: return []
        
        sl, pl, res = [0] * 26, [0] * 26, []
        for i in range(len2):
            sl[ord(s[i]) - 97] += 1
            pl[ord(p[i]) - 97] += 1
        if sl == pl: res.append(0)
        
        for i in range(len2, len1):
            sl[ord(s[i]) - 97] += 1
            sl[ord(s[i - len2]) - 97] -= 1
            if sl == pl: res.append(i - len2 + 1)
        
        return res
        
