# 64ms, 49.61%; 14MB, 5.95%
class Solution:
    def checkPossibility(self, nums: list) -> bool:
        flag = False
        for i in range(1,len(nums)):
            if nums[i] >= nums[i - 1]: continue
            if flag: return False
            flag = True
            if i > 1 and nums[i] < nums[i - 2]: nums[i] = nums[i - 1]
        return True
