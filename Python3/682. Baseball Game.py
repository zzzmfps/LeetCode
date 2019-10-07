# 48ms, 65.25%; 13.9MB, 10.00%
class Solution:
    def calPoints(self, ops: list) -> int:
        scores = []
        for v in ops:
            if v == 'D':
                scores.append(scores[-1] << 1)
            elif v == 'C':
                scores.pop()
            elif v == '+':
                scores.append(scores[-2] + scores[-1])
            else:
                scores.append(int(v))
        return sum(scores)
