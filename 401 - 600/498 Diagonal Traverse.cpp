// 52ms, 100.00%; 14.2MB, 100.00%
auto x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    vector<int> findDiagonalOrder(const vector<vector<int>> &matrix)
    {
        vector<int> res;
        if (matrix.empty()) return res;

        int row = matrix.size(), col = matrix[0].size();
        int i = 0, j = 0, delta = -1;
        res.reserve(row * col);

        for (int k = 0, limit = row + col - 1; k < limit; ++k) {
            while (i >= 0 && i < row && j >= 0 && j < col) {
                res.push_back(matrix[i][j]);
                i += delta, j -= delta;
            }
            if (delta < 0) {
                i += 1;
                if (j == col) i += 1, j -= 1;
            } else {
                j += 1;
                if (i == row) j += 1, i -= 1;
            }
            delta = -delta;
        }
        return res;
    }
};
