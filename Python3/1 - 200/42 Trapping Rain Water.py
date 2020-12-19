# 44ms, 99.68%
class Solution:
    def trap(self, height):
        if len(height) < 3: return 0
        lmax, rmax = height[0], height[-1]
        left, right, water = 1, len(height) - 2, 0
        while left <= right:
            if lmax <= rmax:
                if height[left] > lmax:
                    lmax = height[left]
                else:
                    water += lmax - height[left]
                left += 1
            else:
                if height[right] > rmax:
                    rmax = height[right]
                else:
                    water += rmax - height[right]
                right -= 1
        return water
        
