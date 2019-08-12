# 132ms, 96.60%; 14.4MB, 8.33%
class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        last1, last2 = chr(ord(s[0]) ^ 1), 0
        cur1, cur2 = s[0], 0
        res = 0
        for c in s:
            if c == cur1:
                cur2 += 1
            else:
                res += min(last2, cur2)
                last1, last2 = cur1, cur2
                cur1, cur2 = c, 1
        return res + min(last2, cur2)
