# 56ms, 100.0%
class Solution:
    def moveZeroes(self, nums):
        ins_index, end = 0, len(nums)
        while ins_index < end and nums[ins_index] != 0: ins_index += 1
        trav = ins_index + 1
        while trav < end:
            if nums[trav] != 0:
                nums[trav], nums[ins_index] = nums[ins_index], nums[trav]
                ins_index += 1
            trav += 1
        
