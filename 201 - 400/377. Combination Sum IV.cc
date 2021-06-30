// 4ms, 100.0%; 8.8MB, 58.06%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int combinationSum4(const vector<int> &nums, int target) {
        unsigned *tmp = new unsigned[1 + target]{1};
        for (int i = 1; i <= target; ++i)
            for (auto n : nums)
                if (i >= n) tmp[i] += tmp[i - n];
        return tmp[target];
    }
};
