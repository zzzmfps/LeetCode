# 792ms, 47.09%
class Solution:
    def solveSudoku(self, board):
        self.nums = ['1', '2', '3', '4', '5', '6', '7', '8', '9']
        self.__solveSudoku(board, 0, 0)
    
    def __solveSudoku(self, board, row, col):
        if row == 9: return True
        if col == 9: return self.__solveSudoku(board, row + 1, 0)
        if board[row][col] != '.': return self.__solveSudoku(board, row, col + 1)
        for n in self.nums:
            if self.__check(board, row, col, n):
                board[row][col] = n
                if self.__solveSudoku(board, row, col + 1): return True
                board[row][col] = '.'
        return False
    
    def __check(self, board, row, col, n):
        row1, col1 = row // 3 * 3, col // 3 * 3
        row2, col2 = row1 + 3, col1 + 3
        for i in range(row1, row2):
            for j in range(col1, col2):
                if board[i][j] == n: return False
        for r in range(row1):
            if board[r][col] == n: return False
        for r in range(row2, 9):
            if board[r][col] == n: return False
        for c in range(col1):
            if board[row][c] == n: return False
        for c in range(col2, 9):
            if board[row][c] == n: return False
        return True
                
