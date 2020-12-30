// 6ms, 20.51%
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n));
        for(int c = 0, val = 1 , r = (n + 1) / 2; c < r; ++c)
        {
            if(c == n / 2 && n % 2 != 0)
                res[n / 2][n / 2] = val++;
            for(int col = c; col < n - 1 - c; ++col) res[c][col] = val++;
            for(int row = c; row < n - 1 - c; ++row) res[row][n - 1 - c] = val++;
            for(int col = n - 1 - c; col > c; --col) res[n - 1 - c][col] = val++;
            for(int row = n - 1 - c; row > c; --row) res[row][c] = val++;
        }
        return res;
    }
};
