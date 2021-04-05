// 68 ms, 64.53%; 33.3 MB, 64.78%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum) {
        size_t row = rowSum.size(), col = colSum.size();
        vector<vector<int>> matrix(row, vector<int>(col, -1));

        auto helper = [&](int r1, int c1, int r2, int c2) -> void {
            size_t minSize = min(r2 - r1, c2 - c1);
            for (size_t i = 0; i <= minSize; ++i) {
                size_t rn = i + r1, cn = i + c1;
                int value = min(rowSum[rn], colSum[cn]);
                if (value == rowSum[rn]) {
                    for (size_t j = c1; j <= c2; ++j) matrix[rn][j] = 0;
                } else {
                    for (size_t j = r1; j <= r2; ++j) matrix[j][cn] = 0;
                }
                rowSum[rn] -= value;
                colSum[cn] -= value;
                matrix[rn][cn] = value;
            }
        };

        for (size_t i = 0; i < row; ++i) {
            for (size_t j = 0; j < col; ++j) {
                if (-1 != matrix[i][j]) continue;
                int i2 = i, j2 = j;
                while (i2 + 1 < row && -1 == matrix[i2 + 1][j]) ++i2;
                while (j2 + 1 < col && -1 == matrix[i][j2 + 1]) ++j2;
                helper(i, j, i2, j2);
            }
        }
        return matrix;
    }
};
