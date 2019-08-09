# 36ms, 64.00%; 13.9MB, 25.00%
from math import ceil, log2

class Solution:
    def kthGrammar(self, _, K: int) -> int:
        is_not = False
        while K > 2:
            row = int(ceil(log2(K)))
            if row & 1:
                is_not ^= True
                K -= 2 ** (row - 1)
            else:
                K = 2 ** row - K + 1
        return 2 - K if is_not else K - 1
