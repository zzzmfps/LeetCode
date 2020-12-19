# 32ms, 100.00%; 13.8MB, 100.00%
class Solution:
    def orderlyQueue(self, S: str, K: int) -> str:
        if K > 1: return ''.join(sorted(S))
        _min = min(S)
        idx = S.index(_min)
        res = 'z' * len(S)
        while True:
            res = min(res, S[idx:] + S[:idx])
            idx = S.find(_min, idx + 1)
            if idx < 0: break
        return res
