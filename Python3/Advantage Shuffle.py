# 580ms, 12.88%; 15.9MB, 83.33%
class Solution:
    def advantageCount(self, A: list, B: list) -> list:
        res, tmp = [], sorted(A)
        for b in B:
            idx = self.upper_bound(tmp, b)
            res.append(tmp.pop(idx))
        return res

    def upper_bound(self, arr: list, target: int) -> int:
        if arr[-1] <= target: return 0
        beg, end = 0, len(arr) - 1
        while beg < end:
            mid = (beg + end) // 2
            if arr[mid] > target:
                end = mid
            else:
                beg = mid + 1
        return beg
