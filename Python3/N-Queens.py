# 60ms, 99.25%
class Solution:
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """

        def dfs(queens):
            row = len(queens)
            if row == n:
                res.append(queens[:])
            else:
                for col in range(n):
                    lidx, ridx = row + col, row - col + n - 1
                    if not vertical[col] and not ldiag[lidx] and not rdiag[ridx]:
                        vertical[col] = ldiag[lidx] = rdiag[ridx] = True
                        queens.append('.' * col + 'Q' + '.' * (n - col - 1))
                        dfs(queens)
                        queens.pop()
                        vertical[col] = ldiag[lidx] = rdiag[ridx] = False

        res = []
        vertical, ldiag, rdiag = [False] * n, [False] * (2 * n - 1), [False] * (2 * n - 1)
        dfs([])
        return res
    
