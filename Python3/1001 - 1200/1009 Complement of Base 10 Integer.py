# 32ms, 88.75%; 13.7MB, 6.67%
from math import log2

class Solution:
    def bitwiseComplement(self, N: int) -> int:
        if N == 0: return 1
        return 2 ** (int(log2(N)) + 1) - 1 - N
    
