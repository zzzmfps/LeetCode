# 36ms, 100.0%
class Solution:
    def longestCommonPrefix(self, strs):
        if not strs: return ""
        if len(strs) == 1: return strs[0]
        beg, mid, end = 0, 0, len(strs[0]) - 1
        while beg <= end:
            mid = (beg + end + 1) // 2
            for s in strs:
                if strs[0][:mid + 1] != s[:mid + 1]:
                    end = mid - 1
                    break
            else:
                if end == beg: return strs[0][:mid + 1]
                else:          beg = mid
        return ""
        
