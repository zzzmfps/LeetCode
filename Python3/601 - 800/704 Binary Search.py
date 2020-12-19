# 48ms, 89.93%; 14MB, 5.19%
class Solution:
    def search(self, nums: list, target: int) -> int:
        i, j = 0, len(nums) - 1
        while i <= j:
            mid = (i + j) // 2
            if nums[mid] == target: return mid
            if nums[mid] > target:
                j = mid - 1
            else:
                i = mid + 1
        return -1
