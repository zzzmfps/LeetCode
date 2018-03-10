# 752ms, 99.81%
class Solution:
    def threeSum(self, nums):
        nums.sort()
        res, length = [], len(nums)
        for i in range(length - 2):
            if i > 0 and nums[i] == nums[i - 1]: continue
            j, k, target = i + 1, length - 1, -nums[i]
            while j < k:
                part = nums[j] + nums[k]
                if part < target:
                    j += 1
                elif part > target:
                    k -= 1
                else:
                    res.append([nums[i], nums[j], nums[k]])
                    while j < k and nums[j] == nums[j + 1]: j += 1
                    while j < k and nums[k] == nums[k - 1]: k -= 1
                    j, k = j + 1, k - 1
        return res
    
