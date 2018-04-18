# 36ms, 100.0%
class Solution:
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        dist = x ^ y
        count = 0
        while dist:
            count += dist & 1
            dist >>= 1
        return count
    
