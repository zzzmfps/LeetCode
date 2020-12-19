# 36ms, 86.38%; 13.9MB, 100.00%
from heapq import *


class Solution:
    def lastStoneWeight(self, stones: list) -> int:
        tmp = [-s for s in stones]
        heapify(tmp)
        while len(tmp) > 1:
            x = heappop(tmp)
            y = heappop(tmp)
            if x == y: continue
            heappush(tmp, x - y)
        return -tmp[0] if tmp else 0
        
