# 36ms, 45.68%; 12.8MB, 100.00%
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        heights2 = sorted(heights)
        return sum([heights[i] != heights2[i] for i in range(len(heights))])
        
