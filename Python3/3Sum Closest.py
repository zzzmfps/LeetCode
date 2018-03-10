# 92ms, 100.0%
class Solution:
    def threeSumClosest(self, nums, target):
        nums.sort()
        res = nums[0] + nums[1] + nums[2]
        dif, end = target - res, len(nums) - 1
        for i in range(end - 1):
            if i > 0 and nums[i] == nums[i - 1]: continue
            j, k = i + 1, end
            while j < k:
                tmp = nums[i] + nums[j] + nums[k]
                dif2 = target - tmp
                if abs(dif2) < abs(dif): res, dif = tmp, dif2
                if dif2 > 0:
                    j += 1
                elif dif2 < 0:
                    k -= 1
                else:
                    return target
        return res
        
