# 84ms, 100.0%
class Solution:
    def longestPalindrome(self, s):
        if len(s) < 2: return s
        max_len, start = 1, 0
        for i in range(1, len(s)):
            tmp = i - max_len - 1    # +1 left and right +1 --> length + 2
            if tmp >= 0 and s[tmp: i + 1] == s[tmp: i + 1][:: -1]:
                start, max_len = tmp, max_len + 2
            tmp = i - max_len    # 0 left and right +1 --> length + 1
            if tmp >= 0 and s[tmp: i + 1] == s[tmp: i + 1][:: -1]:
                start, max_len = tmp, max_len + 1
        return s[start: start + max_len]
    
