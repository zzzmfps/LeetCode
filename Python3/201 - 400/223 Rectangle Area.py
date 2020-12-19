# 120ms, 75.47%
class Solution:
    def computeArea(self, A, B, C, D, E, F, G, H):
        """
        :type A: int
        :type B: int
        :type C: int
        :type D: int
        :type E: int
        :type F: int
        :type G: int
        :type H: int
        :rtype: int
        """
        area1 = abs(A - C) * abs(B - D)
        area2 = abs(E - G) * abs(F - H)
        if C < E or G < A or H < B or D < F:
            area3 = 0
        else:
            x = sorted([A, C, E, G])
            y = sorted([B, D, F, H])
            area3 = abs(x[1] - x[2]) * abs(y[1] - y[2])
        return area1 + area2 - area3
