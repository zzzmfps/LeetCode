// 20ms, 99.70%; 11.9MB, 81.56%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int kthSmallest(const vector<vector<int>> &matrix, int k) {
        int _min = matrix.front().front(), _max = matrix.back().back();
        int n = matrix.size();
        while (_min < _max) {
            int mid = _min + (_max - _min) / 2, count = 0;
            for (int i = 0; i < n; ++i) {
                if (matrix[i][0] > mid) continue;
                int l = 0, r = n - 1;
                while (l < r) {
                    int m = (l + r + 1) / 2;
                    if (matrix[i][m] <= mid) {
                        l = m;
                    } else {
                        r = m - 1;
                    }
                }
                count += 1 + l;
            }
            if (count < k) {
                _min = mid + 1;
            } else {
                _max = mid;
            }
        }
        return _min;
    }
};
