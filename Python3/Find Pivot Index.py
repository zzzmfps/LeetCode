# 72ms, 74.91%
class Solution:
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums: return -1
        sums, size = nums[:], len(nums)
        for i in range(1, size):
            sums[i] = sums[i - 1] + nums[i]

        if sums[0] == sums[-1]: return 0
        size -= 1
        for i in range(1, size):
            if sums[-1] - sums[i] == sums[i - 1]: return i
        if sums[size - 1] == 0: return size
        return -1
