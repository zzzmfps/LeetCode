# 52ms, 100.0%
class Solution:
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        size, ret = len(nums), float('inf')
        end = sums = 0
        for start in range(size):
            while sums < s:
                if end == size: break
                sums += nums[end]
                end += 1
            else:
                ret = min(ret, end - start)
                sums -= nums[start]
        return 0 if ret == float('inf') else ret
