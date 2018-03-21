# 40ms, 97.34%
class Solution:
    def longestPalindrome(self, s):
        memo = {}
        for ch in s:
            if memo.get(ch, 0):
                memo[ch] += 1
            else:
                memo[ch] = 1
        res, length = 1, len(s)
        for m in memo:
            if memo[m] > 1: res += memo[m] & 0xFFFFFFFE
        return res if res < length else length
    
