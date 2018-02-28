# 56ms, 100.0%
class Solution:
    def missingNumber(self, nums):
        res, i = len(nums), 0
        for n in nums:
            res ^= n
            res ^= i
            i += 1
        return res
    
