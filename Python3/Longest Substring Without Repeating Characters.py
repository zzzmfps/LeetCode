# 92ms, 100.0%
class Solution:
    def lengthOfLongestSubstring(self, s):
        lst, count, res = [], 0, 0
        for ch in s:
            if ch in lst:
                idx = lst.index(ch) + 1
                lst[: idx], count, res = [], count - idx, max(count, res)
            count += 1
            lst.append(ch)
        return max(count, res)
    
