# 84ms, 64.41%; 13.3MB, 27.40%
# Definition for a point.
# class Point:
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

class Solution:
    def maxPoints(self, points: list) -> int:
        length = len(points)
        if length < 3: return length
        res, i = 2, 0
        while i < length - res:
            j = i + 1
            tmp = dict()
            cur, same = 0, 0
            while j < length:
                x_diff = points[i].x - points[j].x
                y_diff = points[i].y - points[j].y
                if x_diff == 0 and y_diff == 0:
                    same += 1
                else:
                    d = self.__gcd(x_diff, y_diff)
                    xy = (x_diff // d, y_diff // d)
                    if xy in tmp:
                        tmp[xy] += 1
                    else:
                        tmp[xy] = 1
                    cur = max(cur, tmp[xy])
                j += 1
            i += 1
            res = max(res, 1 + cur + same)
        return res

    def __gcd(self, x: int, y: int) -> int:
        return y if x == 0 else self.__gcd(y % x, x)
