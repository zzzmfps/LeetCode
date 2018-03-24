# 68ms, 78.91%
class Solution:
    def isValidSudoku(self, board):
        row, col, block = [0] * 9, [0] * 9, [0] * 9
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    idx = 1 << (ord(board[i][j]) - 49)
                    bidx = i // 3 * 3 + j // 3
                    if (row[i] & idx) or (col[j] & idx) or (block[bidx] & idx):
                        return False
                    row[i] |= idx
                    col[j] |= idx
                    block[bidx] |= idx
        return True
    
