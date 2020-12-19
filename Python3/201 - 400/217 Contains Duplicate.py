# 48ms, 100.0%
class Solution:
    def containsDuplicate(self, nums):
        return len(nums) != len(set(nums))
    
