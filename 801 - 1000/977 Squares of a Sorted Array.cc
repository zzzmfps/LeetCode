// 84ms, 99.84%; 13.3MB, 100.0%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> sortedSquares(vector<int> &A) {
        vector<int> res;
        res.resize(A.size());
        int i = 0, j = A.size() - 1;
        while (i <= j)
            if (abs(A[i]) > abs(A[j])) {
                res[j - i] = A[i] * A[i];
                ++i;
            } else {
                res[j - i] = A[j] * A[j];
                --j;
            }
        return res;
    }
};
