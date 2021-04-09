// 388 ms, 50.40%; 93.2 MB, 70.08%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>> &tasks) {
        auto sortRule = [&](const vector<int> &v1, const vector<int> &v2) {
            int diff1 = v1[1] - v1[0], diff2 = v2[1] - v2[0];
            return diff1 < diff2 || diff1 == diff2 && v1[0] > v2[0];
        };
        sort(tasks.begin(), tasks.end(), sortRule);

        auto accRule = [](int pre, const vector<int> &v) { return max(v[1], pre + v[0]); };
        return accumulate(tasks.begin(), tasks.end(), 0, accRule);
    }
};
