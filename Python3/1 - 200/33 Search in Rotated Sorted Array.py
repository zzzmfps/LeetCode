# 44ms, 100.0%
class Solution:
    def search(self, nums, target):
        if not nums: return -1
        trav, end = 0, len(nums) - 1
        if nums[0] == target: return 0
        elif nums[0] < target:
            while trav < end and nums[trav] < target:
                trav += 1
        elif nums[-1] == target: return end
        elif nums[-1] > target:
            trav = end
            while trav > 0 and nums[trav] > target:
                trav -= 1
        return trav if nums[trav] == target else -1
    
