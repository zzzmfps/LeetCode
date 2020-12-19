# 236ms, 44.86%
class Solution:
    def largestTriangleArea(self, points):
        """
        :type points: List[List[int]]
        :rtype: float
        """

        def get_area(i, j, k):
            p1, p2, p3 = points[i], points[j], points[k]
            return abs((p2[0] - p1[0]) * (p3[1] - p1[1]) - (p3[0] - p1[0]) * (p2[1] - p1[1]))

        pts, max_area = len(points), 0.0
        for i in range(pts - 2):
            for j in range(i + 1, pts - 1):
                for k in range(j + 1, pts):
                    max_area = max(max_area, get_area(i, j, k))
        return 0.5 * max_area
