// 12ms, 70.22%; 9.3MB, 84.00%
class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> A)
    {
        for (auto &row : A) {
            for (auto &v : row) v ^= 1;
            reverse(row.begin(), row.end());
        }
        return A;
    }
};
