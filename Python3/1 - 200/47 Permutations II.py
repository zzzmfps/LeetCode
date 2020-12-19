# 108ms, 61.88%
class Solution:
    def permuteUnique(self, nums):
        res = [nums]
        while True:
            tmp = self.nextPermutation(res[-1][:])
            if tmp == res[0]: break
            res.append(tmp)
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
    
