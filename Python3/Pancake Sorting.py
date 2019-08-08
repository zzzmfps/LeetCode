# 44ms, 91.37%; 13.9MB, 100.00%
class Solution:
    def pancakeSort(self, A: list) -> list:
        res = []
        for i in range(len(A) - 1, 0, -1):
            if A[i] == i + 1: continue
            idx = A.index(i + 1, 0, i + 1)
            if idx:
                A = A[idx::-1] + A[idx + 1:]
                res.append(idx + 1)
            A = A[i::-1] + A[i + 1:]
            res.append(i + 1)
        return res
