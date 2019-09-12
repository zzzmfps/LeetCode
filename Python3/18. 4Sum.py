# 88ms, 100.0%
class Solution:
    def fourSum(self, nums, target):
        nums.sort()
        res, end = [], len(nums) - 1
        for i in range(end - 2):
            if i > 0 and nums[i] == nums[i - 1]: continue
            if sum(nums[i: i + 4]) > target: break
            if nums[i] + sum(nums[-3:]) < target: continue
            for j in range(i + 1, end - 1):
                if j > i + 1 and nums[j] == nums[j - 1]: continue
                if nums[i] + sum(nums[j: j + 3]) > target: break
                if nums[i] + nums[j] + sum(nums[-2:]) < target: continue
                k, l, part = j + 1, end, target - nums[i] - nums[j]
                while k < l:
                    tmp = part - nums[k] - nums[l]
                    if tmp > 0:
                        k += 1
                    elif tmp < 0:
                        l -= 1
                    else:
                        res.append([nums[i], nums[j], nums[k], nums[l]])
                        while(k < l and nums[k + 1] == nums[k]): k += 1
                        while(k < l and nums[l - 1] == nums[l]): l -= 1
                        k, l = k + 1, l - 1
        return res
    
