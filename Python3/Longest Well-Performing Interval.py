# 256ms, 42.80%; 14.3MB, 100.00%
class Solution:
    def longestWPI(self, hours: list) -> int:
        res = score = 0
        tmp = {}
        for i, h in enumerate(hours):
            score += 1 if h > 8 else -1
            if score > 0:
                res = i + 1
            tmp.setdefault(score, i)
            if score - 1 in tmp:
                res = max(res, i - tmp[score - 1])
        return res
