# 228ms, 76.72%
class Solution:
    def triangleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = sorted([n for n in nums if n != 0], reverse=True)
        res, end = 0, len(nums) - 1
        for i in range(end - 1):
            j, k = i + 1, end
            while j < k:
                if nums[j] + nums[k] > nums[i]:
                    res += k - j
                    j += 1
                else:
                    k -= 1
        return res
    
