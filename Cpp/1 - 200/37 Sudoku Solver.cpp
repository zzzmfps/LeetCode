// 14ms, 43.6%
class Solution
{
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        solveSudoku(board, 0, 0);
    }
    
private:
    bool solveSudoku(vector<vector<char>> &board, int i, int j)
    {
        if(i == 9) return true;
        if(j == 9) return solveSudoku(board, i + 1, 0);
        if(board[i][j] != '.') return solveSudoku(board, i, j + 1);
        for(char c = '1'; c <= '9'; ++c)
            if(check(board, i, j, c))
            {
                board[i][j] = c;
                if(solveSudoku(board, i, j + 1)) return true;
                board[i][j] = '.';
            }
        return false;
    }
    
    bool check(vector<vector<char>> &board, int i, int j, char val)
    {
        int row1 = i / 3 * 3, row2 = row1 + 2;
        int col1 = j / 3 * 3, col2 = col1 + 2;
        for(int r = row1; r <= row2; ++r)
            for(int c = col1; c <= col2; ++c)
                if(board[r][c] == val) return false;
        for(int r = 0; r < row1; ++r) if(board[r][j] == val) return false;
        for(int r = 8; r > row2; --r) if(board[r][j] == val) return false;
        for(int c = 0; c < col1; ++c) if(board[i][c] == val) return false;
        for(int c = 8; c > col2; --c) if(board[i][c] == val) return false;
        return true;
    }
};
