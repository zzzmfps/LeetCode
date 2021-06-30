// 116ms, 74.14%; 17.7MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        res.push_back(vector<int>{r0, c0});
        int rx = abs(R - 1 - r0), cx = abs(C - 1 - c0);
        int maxDiff = max({r0 + c0, rx + c0, r0 + cx, rx + cx});
        for (int i = 1; i <= maxDiff; ++i) {
            if (c0 - i >= 0) res.push_back(vector<int>{r0, c0 - i});
            for (int cd = 1 - i; cd < i; ++cd) {
                int c = c0 + cd;
                if (c < 0 || c >= C) continue;
                int rd = i - abs(cd), r1 = r0 - rd, r2 = r0 + rd;
                if (r1 >= 0) res.push_back(vector<int>{r1, c});
                if (r2 < R) res.push_back(vector<int>{r2, c});
            }
            if (c0 + i < C) res.push_back(vector<int>{r0, c0 + i});
        }
        return res;
    }
};
