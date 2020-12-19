# 44ms, 73.29%; 14.1MB, 5.56%
class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        res = []
        tmp, beg, i, size = 0, 1, 1, len(S)
        while i < size:
            if tmp == 0 and S[i] == ')':
                res.append(S[beg:i])
                beg = i = i + 2
                tmp = 0
            else:
                tmp += (1 if S[i] == '(' else -1)
                i += 1
        return ''.join(res)
