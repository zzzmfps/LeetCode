# 56ms, 78.57%
class Solution:
    def canJump(self, nums):
        jump, length = nums[0], len(nums)
        for i in range(length):
            if jump < i: return False
            jump = max(jump, i + nums[i])
        return True
    
