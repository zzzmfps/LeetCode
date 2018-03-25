# 108ms, 79.68%
class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        two = nums1 + nums2
        length = len(two)
        is_odd = length & 1
        two.sort()
        if is_odd: return float(two[length // 2])
        return (two[(length - 1) // 2] + two[length // 2]) / 2
    
