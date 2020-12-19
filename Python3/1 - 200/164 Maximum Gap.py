# 44ms, 97.85%
class Solution:
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length, max_gap = len(nums), 0
        if length < 2: return 0
        nums.sort()
        for i in range(1, length):
            max_gap = max(max_gap, nums[i] - nums[i - 1])
        return max_gap
    
