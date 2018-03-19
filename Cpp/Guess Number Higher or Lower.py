# 30ms, 85.21%
class Solution(object):
    def guessNumber(self, n):
        beg = 1
        while beg <= n:
            mid = (beg + n) // 2
            res = guess(mid)
            if res > 0:
                beg = mid + 1
            elif res < 0:
                n = mid - 1
            else:
                return mid
        
