# 128ms, 73.24%; 14.2MB, 5.71%
class Solution:
    def findClosestElements(self, arr: list, k: int, x: int) -> list:
        if arr[-1] <= x: return arr[-k:]
        i = self.__binary_search(arr, k, x)
        while i > 0 and x - arr[i - 1] <= arr[i + k - 1] - x:
            i -= 1
        return arr[i:i + k]

    def __binary_search(self, arr: list, k: int, x: int) -> int:
        size = len(arr)
        i, j = 0, size - 1
        while i < j:
            mid = (i + j) // 2
            if arr[mid] <= x:
                i = mid + 1
            else:
                j = mid
        return min(i, size - k)
