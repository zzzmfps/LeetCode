# 40ms, 100.0%
class Solution:
    def lengthOfLastWord(self, s):
        s = s.strip()
        if not s: return 0
        i, slen = -1, -len(s)
        while i > slen:
            if s[i - 1] == ' ': break;
            i -= 1
        return -i
        
