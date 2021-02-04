// 5ms, 37.22%
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int round = matrix.size() / 2;
        while(--round >= 0)
            circle(matrix, round);
    }
    
private:
    void circle(vector<vector<int>> &c, int k)
    {
        int n = c.size() - k - 1;
        for(int i = 0; i < n - k; ++i)
        {
            int tmp = c[k][k + i];
            c[k][k + i] = c[n - i][k];
            c[n - i][k] = c[n][n - i];
            c[n][n - i] = c[k + i][n];
            c[k + i][n] = tmp;
        }
    }
};
