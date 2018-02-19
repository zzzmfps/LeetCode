# 36ms, 100.0%
class Solution:
    def removeElement(self, nums, val):
        count, length = 0, len(nums)
        for i in range(length):
            if nums[i - count] == val:
                nums[i - count: i - count + 1] = []
                count += 1
        return length - count
        
