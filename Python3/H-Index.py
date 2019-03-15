# 40ms, 58.81%; 13.2MB, 5.88%
class Solution:
    def hIndex(self, citations: list) -> int:
        if not citations: return 0
        citations.sort(reverse=1)
        length = len(citations)
        if citations[0] == 0: return 0
        if citations[-1] >= length: return length
        for i in range(1, len(citations)):
            if citations[i - 1] >= i and citations[i] <= i:
                break
        return i
