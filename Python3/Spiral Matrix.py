# 40ms, 79.78%
class Solution:
    def spiralOrder(self, matrix):
        if not matrix: return matrix
        m, n = len(matrix), len(matrix[0])
        u, l, d, r, k = 0, 0, m - 1, n - 1, 0
        res = [0] * (m * n)
        while True:
            for col in range(l, r + 1):
                res[k] = matrix[u][col]
                k += 1
            if u == d: break
            u += 1
            
            for row in range(u, d + 1):
                res[k] = matrix[row][r]
                k += 1
            if r == l: break
            r -= 1
            
            for col in range(r, l - 1, -1):
                res[k] = matrix[d][col]
                k += 1
            if d == u: break
            d -= 1
                
            for row in range(d, u - 1, -1):
                res[k] = matrix[row][l]
                k += 1
            if l == r: break
            l += 1
        return res
                
