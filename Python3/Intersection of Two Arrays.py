# 44ms, 91.75%
class Solution:
    def intersection(self, nums1, nums2):
        return list(set(nums1) & set(nums2))
    
