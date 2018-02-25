# 46ms, 87.17%
class Solution(object):
    def majorityElement(self, nums):
        cur, count = nums[0], 0
        for num in nums:
            if cur == num:
                count += 1
            else:
                count -= 1
                if count == 0:
                    cur, count = num, 1
        return cur
        '''
        ### 45ms, 89.88%
        return sorted(nums)[len(nums) / 2]
        '''
        
