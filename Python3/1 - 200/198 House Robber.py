# 40ms, 100.0%
class Solution:
    def rob(self, nums):
        max_a = max_b = 0
        for n in nums:
            max_a, max_b = max_b, max(max_a + n, max_b)
        return max_b
    
