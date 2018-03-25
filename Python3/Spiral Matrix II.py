# 48ms, 54.13%
class Solution:
    def generateMatrix(self, n):
        if not n: return []
        res = [[0] * n for _ in range(n)]
        l, u, r, d, num = 0, 0, n - 1, n - 1, 1
        while True:
            for col in range(l, r + 1):
                res[u][col] = num
                num += 1
            if u == d: break
            u += 1
            for row in range(u, d + 1):
                res[row][r] = num
                num += 1
            if r == l: break
            r -= 1
            for col in range(r, l - 1, -1):
                res[d][col] = num
                num += 1
            if d == u: break
            d -= 1
            for row in range(d, u - 1, -1):
                res[row][l] = num
                num += 1
            if l == r: break
            l += 1
        return res
        
