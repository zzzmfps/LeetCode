# 0, brute force, T(n) = O(nlogn)
# 36ms, 45.68%; 12.8MB, 100.00%
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        heights2 = sorted(heights)
        return sum([heights[i] != heights2[i] for i in range(len(heights))])
        

# 1, based on count-sort, T(n) = O(n)
# 32ms, 77.12%; 12.9MB, 100.00%, not obviously enough
from collections import Counter

class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        res, idx = 0, 0
        for val, count in sorted(Counter(heights).items()):
            while count:
                count -= 1
                res += (val != heights[idx])
                idx += 1
        return res
    
