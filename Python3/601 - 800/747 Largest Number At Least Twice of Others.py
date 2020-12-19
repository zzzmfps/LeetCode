# 36ms, 99.74%; 13.1MB, 6.82%
class Solution:
    def dominantIndex(self, nums: list) -> int:
        size = len(nums)
        if size == 1: return 0
        max_index, second = (0, 1) if nums[0] > nums[1] else(1, 0)
        for i in range(2, size):
            if nums[i] > nums[max_index]:
                max_index, second = i, max_index
            elif nums[i] > nums[second]:
                second = i
        return max_index if nums[max_index] >= 2 * nums[second] else - 1
