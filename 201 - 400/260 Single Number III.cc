// 4ms, 100.0%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> singleNumber(const vector<int> &nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, [](int x, int y) { return x ^ y; });
        diff &= -diff;
        vector<int> rets{0, 0};
        for (const auto n : nums) rets[(n & diff) == 0 ? 0 : 1] ^= n;
        return rets;
    }
};
