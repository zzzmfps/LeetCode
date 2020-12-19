# 40ms, 75.38%; 13.3MB, 5.63%
class Solution:
    def findMin(self, nums: list) -> int:
        if nums[0] == nums[-1]:
            j = len(nums) - 1
            while j > 0 and nums[j] == nums[-1]:
                j -= 1
            nums = nums[:1 + j]

        length = len(nums)
        if length == 1 or nums[0] < nums[-1]: return nums[0]
        if length == 2: return min(nums)
        if nums[1] < nums[0] and nums[1] > nums[-1]: return nums[-1]
        
        i, j = 0, length - 1
        while i < j:
            mid = (i + j) // 2
            if nums[mid] >= nums[0]:
                i = mid + 1
            else:
                j = mid
        return nums[i]
