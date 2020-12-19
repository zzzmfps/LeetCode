# 36ms, 99.81%; 13.1MB, 100.00%
class Solution:
    def numRookCaptures(self, board: list) -> int:
        for i in range(8):
            if 'R' in board[i]:
                j = board[i].index('R')
                break
        res = 0
        for newi in range(i - 1, -1, -1):
            if board[newi][j] == '.': continue
            if board[newi][j] == 'p': res += 1
            break
        for newi in range(i + 1, 8):
            if board[newi][j] == '.': continue
            if board[newi][j] == 'p': res += 1
            break
        for newj in range(j - 1, -1, -1):
            if board[i][newj] == '.': continue
            if board[i][newj] == 'p': res += 1
            break
        for newj in range(j + 1, 8):
            if board[i][newj] == '.': continue
            if board[i][newj] == 'p': res += 1
            break
        return res
        
