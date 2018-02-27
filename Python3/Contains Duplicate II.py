# 48ms, 100.0%
class Solution:
    def containsNearbyDuplicate(self, nums, k):
        dic = {}
        for index, num in enumerate(nums):
            if num in dic and index - dic[num] <= k:
                return True
            dic[num] = index
        return False
        
