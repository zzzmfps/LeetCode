# 108ms, 90.51%
class Solution:
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        size = len(nums)
        res = [1] * size
        for i in range(1, size):
            res[i] = res[i - 1] * nums[i - 1]
        right = 1
        for i in range(size - 2, -1, -1):
            right *= nums[i + 1]
            res[i] *= right
        return res
    
