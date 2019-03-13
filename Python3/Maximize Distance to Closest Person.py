# 52ms, 86.87%; 13.5MB, 5.55%
class Solution:
    def maxDistToClosest(self, seats: list) -> int:
        beg, end = self.__find(seats), self.__find(seats, reverse=1)
        res = max(beg, len(seats) - end - 1)
        for i in range(beg + 1, end + 1):
            if seats[i] == 0: continue
            res = max(res, (i - beg) // 2)
            beg = i
        return res

    def __find(self, seats: list, reverse: int=0):
        if reverse == 0:
            beg, end, step = 0, len(seats), 1
        else:
            beg, end, step = len(seats) - 1, -1, -1
        for i in range(beg, end, step):
            if seats[i] == 1: return i
        return -1   # not needed
