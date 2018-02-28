# 32ms, 28.37%
class Solution:
    def firstBadVersion(self, n):
        beg = 1
        while beg < n:
            mid = (beg + n) // 2
            if isBadVersion(mid):
                n = mid
            else:
                beg = mid + 1
        return beg
    
