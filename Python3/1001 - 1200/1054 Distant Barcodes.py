# 568ms, 46.49%; 16.4MB, 100.00%
from collections import Counter

class Solution:
    def rearrangeBarcodes(self, barcodes: list) -> list:
        count,size = Counter(barcodes), len(barcodes)
        barcodes.sort(key=lambda x: (count[x], x))
        res = [0] * size
        res[1::2], res[::2] = barcodes[0:size // 2], barcodes[size // 2:]
        return res
