# 88ms, 97.85%
class Solution:
    def removeDuplicates(self, nums):
        length = len(nums)
        if length < 2: return length
        cur, beg, count = nums[0], 0, 0
        for i in range(1, length):
            if cur != nums[i - count]:
                cur = nums[i - count]
                if beg + 1 == i - count:
                    beg = i - count
                else:
                    nums[beg + 1: i - count] = []
                    count += i - count - beg - 1
                    beg += 1
        nums[beg + 1: ] = []
        return beg + 1
        
