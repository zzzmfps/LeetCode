# 80ms, 22.97%; 14.4MB, 14.29%
class Solution:
    def findRedundantConnection(self, edges: list) -> list:
        n = len(edges)
        matrix = [i for i in range(n + 1)]
        for u, v in edges:
            if self.root(matrix, u) == self.root(matrix, v): return [u, v]
            self.union(matrix, u, v)
        return []

    def root(self, m: list, x: int) -> int:
        tmp = x
        while x != m[x]:
            x = m[x]
        while tmp != x:
            tmp, m[tmp] = m[tmp], x
        return x

    def union(self, m: list, x: int, y: int) -> None:
        xx, yy = self.root(m, x), self.root(m, y)
        if xx != yy: m[xx] = yy
