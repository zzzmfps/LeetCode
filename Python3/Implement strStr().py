# 40ms, 100.0%
class Solution:
    def strStr(self, haystack, needle):
        if not needle: return 0
        trav, i, end1, end2 = 0, 0, len(haystack) - len(needle), len(needle) - 1
        while trav <= end1:
            while haystack[trav + i] == needle[i]:
                if i == end2: return trav
                else: i += 1
            else:
                trav, i = trav + 1, 0
        return -1
        
