# 36ms, 100.00%; 13.1MB, 100.00%
class Solution:

    def videoStitching(self, clips: list, T: int) -> int:
        arr = [0] * 101
        for f, t in clips:
            arr[f] = max(arr[f], t)
        ret, last, cur = 0, 0, 0
        while cur < T:
            idx = self.__find_max_index(arr, last, cur)
            if arr[idx] <= cur: return - 1
            last, cur = idx + 1, arr[idx]
            ret += 1
        return ret

    def __find_max_index(self, arr: list, i: int, j: int) -> int:
        idx, tmp = 0, 0
        for k in range(i, j + 1):
            if arr[k] > tmp:
                idx, tmp = k, arr[k]
        return idx
