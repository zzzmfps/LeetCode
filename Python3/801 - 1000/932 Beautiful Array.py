# 48ms, 60.92%; 13.3MB, 9.09%
class Solution:
    def beautifulArray(self, N: int) -> list:
        res = [i for i in range(1, 1 + N)]
        self.__helper(res, 0, len(res))
        return res

    def __helper(self, arr: list, i: int, j: int) -> None:
        if j - i < 3: return
        arr[i:j] = arr[i:j:2] + arr[i + 1:j:2]
        k = (i + j + 1) >> 1
        self.__helper(arr, i, k)
        self.__helper(arr, k, j)
        
