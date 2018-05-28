# 1004ms, 92.98%
class Solution:
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        n = len(points)
        dists, num = [0] * n, 0
        for p in points:
            for i in range(n):
                xdiff, ydiff = p[0] - points[i][0], p[1] - points[i][1]
                dists[i] = xdiff * xdiff + ydiff * ydiff
            dists.sort()
            k = 1
            for i in range(1, n):
                if (dists[i] == dists[i - 1]):
                    k += 1
                else:
                    num += k * (k - 1)
                    k = 1
            num += k * (k - 1)
        return num
    
