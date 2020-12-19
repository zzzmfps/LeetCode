# 132ms, 27.45%; 14.1MB, 100.00%
class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        res = arr[:-1] + [-1]
        for i in range(len(arr) - 1, 0, -1):
            res[i - 1] = max(res[i], arr[i])
        return res
