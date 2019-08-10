# 312ms, 40.74%; 14.2MB, 7.14%
class Solution:
    def findLongestChain(self, pairs: list) -> int:
        pairs.sort(key=lambda x: x[0])
        last, idx, res, length = -float('inf'), 0, 0, len(pairs)
        while True:
            while idx < length and pairs[idx][0] <= last: idx += 1
            if idx == length: break
            res += 1
            first, last = min(pairs[idx:], key=lambda x: x[1])
            idx = pairs.index([first, last]) + 1
        return res
