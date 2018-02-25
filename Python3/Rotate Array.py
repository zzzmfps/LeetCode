# 56ms, 100.0%
class Solution:
    def rotate(self, nums, k):
        length = len(nums)
        k %= length
        n = length - k
        nums.extend(nums[: n])
        nums[: n] = []
        '''
        ### 56ms, 100.0%
        k %= len(nums)
        if k != 0: nums[: 0], nums[-k: ] = nums[-k: ], []
        '''
