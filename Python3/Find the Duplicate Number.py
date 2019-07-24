# 72ms, 90.99%; 16MB, 7.65%
class Solution:
    def findDuplicate(self, nums: list) -> int:
        tmp = [False] * len(nums)
        for n in nums:
            if tmp[n]: return n
            tmp[n] = True
        
