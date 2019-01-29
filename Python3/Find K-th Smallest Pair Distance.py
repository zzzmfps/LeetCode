# 104ms, 76.67%
class Solution:
    def smallestDistancePair(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums = sorted(nums)
        size, low, high = len(nums), 0, nums[-1] - nums[0]
        while low < high:
            count, mid = 0, (low + high) // 2
            j = 1
            for i in range(size - 1):
                while j < size and nums[j] - nums[i] <= mid:
                    j += 1
                count += j - i - 1
            if count < k:
                low = mid + 1
            else:
                high = mid
        return low
