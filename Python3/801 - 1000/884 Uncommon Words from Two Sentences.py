# 28ms, 68.69%; 12.9MB, 100.00%
from collections import Counter


class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        return [x for x, y in Counter(A.split() + B.split()).items() if y == 1]
