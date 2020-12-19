# 36ms, 100.0%
class Solution:
    def searchInsert(self, nums, target):
        for i in range(len(nums)):
            if nums[i] >= target:
                return i
        else:
            return i + 1
        
