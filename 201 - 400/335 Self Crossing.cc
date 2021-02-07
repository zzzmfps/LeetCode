// 4ms, 100.0%; 8.5MB, 7.14%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isSelfCrossing(const vector<int> &x) {
        for (int i = 3, size = x.size(); i < size; ++i) {
            if (x[i - 3] >= x[i - 1] && x[i - 2] <= x[i]) return true;
            if (i < 4) continue;
            if (x[i - 3] == x[i - 1] && x[i] + x[i - 4] >= x[i - 2]) return true;
            if (i < 5) continue;
            if (x[i - 2] > x[i - 4] && x[i - 1] <= x[i - 3] && x[i - 1] + x[i - 5] >= x[i - 3] &&
                x[i] + x[i - 4] >= x[i - 2])
                return true;
        }
        return false;
    }
};
