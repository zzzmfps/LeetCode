# 64ms, 100.0%
class Solution:
    def maximumProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        import heapq
        max3 = heapq.nlargest(3, nums)
        min2 = heapq.nsmallest(2, nums)
        res1 = max3[0] * max3[1] * max3[2]
        res2 = max3[0] * min2[0] * min2[1]
        return res1 if res1 > res2 else res2
    
