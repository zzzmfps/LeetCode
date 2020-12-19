# 1520ms, 16.66%; 14.8MB, 50.00%
class Solution:
    def numDecodings(self, s: str) -> int:
        if s[0] == '0': return 0
        n2, n1, n0 = 1, (9 if s[0] == '*' else 1), 0
        for i in range(1, len(s)):
            n0 = n1 * (9 if s[i] == '*' else 0 if s[i] == '0' else 1)
            if s[i - 1] == '*' and s[i] == '*':
                n0 += n2 * 15
            elif s[i] == '*':
                if s[i - 1] == '1':
                    n0 += n2 * 9
                elif s[i - 1] == '2':
                    n0 += n2 * 6
            elif s[i - 1] == '*':
                n0 += n2 * (1 if s[i] in '789' else 2)
            elif 10 <= int(s[i - 1:i + 1]) <= 26:
                n0 += n2
            n2, n1, n0 = n1, n0, 0
        return n1 % 1000000007
