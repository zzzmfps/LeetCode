// 20ms, 80.00%; 11.2MB, 51.85%
class Solution
{
public:
    int maximalSquare(const vector<vector<char>> &matrix)
    {
        if (matrix.empty()) return 0;
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        int length = helper(matrix, dp);
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (matrix[i][j] == '0') continue;
                dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                length = max(length, dp[i][j]);
            }
        }
        return length * length;
    }

private:
    int helper(const vector<vector<char>> &matrix, vector<vector<int>> &dp)
    {
        int flag = 0;
        int row = matrix.size(), col = matrix[0].size();
        for (int i = 0; i < row; ++i)
            if (matrix[i][0] == '1') dp[i][0] = flag = 1;
        for (int j = 1; j < col; ++j)
            if (matrix[0][j] == '1') dp[0][j] = flag = 1;
        return flag;
    }
};
