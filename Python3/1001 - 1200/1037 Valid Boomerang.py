# 28ms, 79.19%; 12.7MB, 100.00%
class Solution:
    def isBoomerang(self, points: List[List[int]]) -> bool:
        k1 = (points[0][0] - points[1][0], points[0][1] - points[1][1])
        k2 = (points[0][0] - points[2][0], points[0][1] - points[2][1])
        return k1[0] * k2[1] != k1[1] * k2[0]
