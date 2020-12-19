# 68ms, 66.48%; 14.6MB, 33.54%
class Solution:
    def largestRectangleArea(self, heights: list) -> int:
        heights.append(0)
        res, stack = 0, [] 
        i, size = 0, len(heights)
        while i < size:
            if not stack or heights[i] > heights[stack[-1]]:
                stack.append(i)
                i += 1
            else:
                tmp = stack.pop()
                res = max(res, heights[tmp] * (i if not stack else i - stack[-1] - 1))                
        return res
