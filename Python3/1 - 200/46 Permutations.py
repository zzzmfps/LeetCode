# 60ms, 65.24%
class Solution:
    def permute(self, nums):
        res, length, kinds = [nums], len(nums), 1
        for i in range(2, length + 1): kinds *= i
        for _ in range(kinds - 1):
            res.append(self.nextPermutation(res[-1][:]))
        return res
    
    def nextPermutation(self, nums):
        index = len(nums) - 2
        while index >= 0 and nums[index] >= nums[index + 1]:
            index -= 1
        ub = index + 1
        if index >= 0:
            for i in range(index + 2, len(nums)):
                if nums[i] > nums[index] and nums[i] <= nums[ub]:
                    ub = i
            nums[index], nums[ub] = nums[ub], nums[index]
        nums[index + 1:] = nums[index + 1:][::-1]
        return nums
    
