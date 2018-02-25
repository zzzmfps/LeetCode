# 52ms, 100.0%
class Solution:
    def majorityElement(self, nums):
        cur, count = nums[0], 0
        for num in nums:
            if cur == num:
                count += 1
            else:
                count -= 1
                if count == 0: cur, count = num, 1
        return cur
        '''
        ### 52ms, 100.0%
        return sorted(nums)[len(nums) // 2]
        '''
        
