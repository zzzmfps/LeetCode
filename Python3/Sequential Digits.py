# 24ms, 85.96%; 12.8MB, 100.00%
from typing import List
from math import log10


class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        seq = '123456789'
        len1, len2 = map(lambda x: 1 + int(log10(x)), (low, high))
        ret = []
        for i in range(len1, 1 + len2):
            for j in range(10 - i):
                tmp = int(seq[j:j + i])
                if low <= tmp <= high: ret.append(tmp)
        return ret
