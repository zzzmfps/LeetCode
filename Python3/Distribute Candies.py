# 128ms, 94.92%
class Solution:
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        half = len(candies) // 2
        kind = len(set(candies))
        return min(half, kind)
    
