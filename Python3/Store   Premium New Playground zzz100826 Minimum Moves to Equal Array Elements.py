# 72ms, 71.51%
class Solution:
    def minMoves(self, nums):
        min_num, res = nums[0], 0
        for n in nums:
            if n < min_num: min_num = n
            res += n - nums[0]
        return res + (nums[0] - min_num) * len(nums)
    
