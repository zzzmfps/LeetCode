# 108ms, 86.59%; 15.7MB, 6.82%
class Solution:
    def findRadius(self, houses: list, heaters: list) -> int:
        houses.sort()
        heaters.sort()
        res, i, size = 0, 1, len(heaters)
        heaters.append(heaters[-1])
        for pos in houses:
            while i < size and heaters[i] <= pos:
                i += 1
            res = max(res, min(abs(pos - heaters[i - 1]), abs(pos - heaters[i])))
        return res
