// 4ms, 100.00%; 9.9MB, 93.85%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        for (int i = 1, end1 = triangle.size(); i < end1; ++i) {
            auto &cur = triangle[i], &last = triangle[i - 1];
            cur[0] += last[0];
            cur.back() += last.back();
            for (int j = 1, end2 = cur.size() - 1; j < end2; ++j) cur[j] += min(last[j - 1], last[j]);
        }
        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};
