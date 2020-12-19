# 56ms, 100.0%
class Solution:
    def maxArea(self, height):
        res, beg, end = 0, 0, len(height) - 1
        while beg < end:
            min_h = min(height[beg], height[end])
            tmp = (end - beg) * min_h
            res = res if res > tmp else tmp
            while beg < end and min_h >= height[beg]: beg += 1
            while beg < end and min_h >= height[end]: end -= 1
        return res
    
