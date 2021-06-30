// 24ms, 100.00%; 9.4MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n);
        for (int i = 0, x = 1, y = n; i < k; ++i) res[i] = (i & 1) ? y-- : x++;
        int delta = (k > 1 && res[k - 2] < res[k - 1]) ? -1 : 1;
        for (int i = k; i < n; ++i) res[i] = res[i - 1] + delta;
        return res;
    }
};
