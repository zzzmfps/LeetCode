# 32ms, 91.99%; 14MB, 100.00%
class Solution:
    def dayOfYear(self, date: str) -> int:
        tmp = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30]
        y, m, d = int(date[:4]), int(date[5:7]), int(date[8:])
        ret = 1 if m > 2 and (y % 400 == 0 or y % 100 != 0 and y % 4 == 0) else 0
        return ret + sum(tmp[:m]) + d
