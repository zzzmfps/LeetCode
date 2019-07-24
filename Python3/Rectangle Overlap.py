# 40ms, 34.48%; 13.9MB, 5.13%
class Solution:
    def isRectangleOverlap(self, rec1: list, rec2: list) -> bool:
        return rec1[0] < rec2[2] and rec1[2] > rec2[0] and rec1[1] < rec2[3] and rec1[3] > rec2[1]
       
