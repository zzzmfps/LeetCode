# 40ms, 71.19%
class Solution:
    def countSegments(self, s):
        if not s: return 0
        count, is_in_segment = 0, False if s[0] == ' ' else True
        for ch in s:
            if is_in_segment:
                if ch == ' ':
                    count += 1
                    is_in_segment = False
            elif ch != ' ':
                is_in_segment = True
        return count if s[-1] == ' ' else count + 1
    
