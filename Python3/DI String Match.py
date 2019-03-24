# 96ms, 47.95%; 14.4MB, 5.62%
class Solution:
    def diStringMatch(self, S: str) -> list:
        length = len(S)
        res = [i for i in range(1 + length)]
        i = S.find('D')
        while i >= 0:
            j = S.find('I', i + 1)
            if j == -1: j = length
            res[i:j + 1] = reversed(res[i:j + 1])
            if j == length: break
            i = S.find('D', j + 1)
        return res
