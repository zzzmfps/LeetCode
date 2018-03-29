# 60ms, 86.32%
class Solution:
    def longestValidParentheses(self, s):
        lens = len(s)
        if lens < 2: return 0
        length, max_len = [0] * lens, 0
        if s[0] == ')': length[0] = -1
        for i in range(1, lens):
            if s[i] == ')':
                if length[i - 1] < 0:
                    length[i] = -1
                elif length[i - 1] == 0:
                    length[i] = 2
                    if i - 2 >= 0: length[i] += max(length[i - 2], 0)
                    max_len = max(length[i], max_len)
                elif length[i - 1] > 0:
                    tmp = i - 1 - length[i - 1]
                    if tmp >= 0 and s[tmp] == '(':
                        length[i] = length[i - 1] + 2
                        if tmp > 0: length[i] += max(length[tmp - 1], 0)
                        max_len = max(length[i], max_len)
                    else:
                        length[i] = -1
        return max_len
    
