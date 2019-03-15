# 588ms, 62.31%; 13.5MB, 8.33%
class Solution:
    def imageSmoother(self, M: list) -> list:
        row, col = len(M), len(M[0])
        res = [[] for _ in range(row)]
        for i in range(row):
            res[i] = [0] * col
            for j in range(col):
                res[i][j] = self.__average(M, i, j)
        return res

    def __average(self, M: list, i: int, j: int) -> int:
        endi, endj = len(M), len(M[0])
        mini, minj = max(0, i - 1), max(0, j - 1)
        maxi, maxj = min(endi,i + 2), min(endj, j + 2)
        acc = sum(sum(x[minj:maxj]) for x in M[mini:maxi])
        return acc // ((maxi - mini) * (maxj - minj))
