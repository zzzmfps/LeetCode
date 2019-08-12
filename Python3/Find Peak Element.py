# 48ms, 96.99%; 13.8MB, 5.88%
class Solution:
    def findPeakElement(self, nums: list) -> int:
        if len(nums) < 3: return nums.index(max(nums))
        if nums[0] > nums[1]: return 0
        if nums[-2] < nums[-1]: return len(nums) - 1

        left, right = 1, len(nums) - 1
        while True:
            mid = (left + right) // 2
            if nums[mid] > nums[mid - 1] and nums[mid] > nums[mid + 1]: return mid
            if nums[mid] < nums[mid - 1]:
                right = mid
            else:
                left = mid + 1
