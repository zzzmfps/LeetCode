// 16ms, 96.04%; 9.7MB, 100.0%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isToeplitzMatrix(const vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            int j = i + 1, k = 1;
            while (j < m && k < n)
                if (matrix[j++][k++] != matrix[i][0]) return false;
        }
        for (int i = 1; i < n; ++i) {
            int j = 1, k = i + 1;
            while (j < m && k < n)
                if (matrix[j++][k++] != matrix[0][i]) return false;
        }
        return true;
    }
};
