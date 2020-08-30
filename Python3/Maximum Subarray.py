# 52ms, 100.0%
class Solution:
    def maxSubArray(self, nums):
        if not nums: return 0
        max_sum = tmp_sum = nums[0]
        for n in nums[1: ]:
            tmp_sum = max(tmp_sum + n, n)
            max_sum = max(tmp_sum, max_sum)
        return max_sum
        
