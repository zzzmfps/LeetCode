# 56ms, 100.0%
class Solution:
    def rotate(self, nums, k):
        k %= len(nums)
        if k != 0: nums[: 0], nums[-k: ] = nums[-k: ], []
