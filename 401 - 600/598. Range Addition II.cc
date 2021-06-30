// 7ms, 100.0%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution {
public:
    int maxCount(int m, int n, const vector<vector<int>> &ops) {
        if (ops.empty()) return m * n;
        int min_a = ops[0][0], min_b = ops[0][1];
        for (const auto &op : ops) {
            if (op[0] < min_a) min_a = op[0];
            if (op[1] < min_b) min_b = op[1];
        }
        return min_a * min_b;
    }
};
