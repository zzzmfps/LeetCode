// 4ms, 96.80%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int lengthOfLIS(const vector<int> &nums) {
        vector<int> res;
        for (const auto n : nums) {
            auto it = lower_bound(res.begin(), res.end(), n);
            if (it == res.end()) {
                res.push_back(n);
            } else {
                *it = n;
            }
        }
        return res.size();
    }
};
