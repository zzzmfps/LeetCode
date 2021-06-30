// 48ms, 100.0%; 12.5MB, 98.64%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> maxSlidingWindow(const vector<int> &nums, int k) {
        vector<int> res;
        if (nums.empty()) return res;

        int limit = nums.size() - k + 1;
        res.reserve(limit--);
        res.push_back(max(nums, 0, k));

        for (int i = 0; i < limit; ++i) {
            int j = i + k, nxt;
            if (nums[j] >= res.back()) {
                nxt = nums[j];
            } else if (nums[i] != res.back()) {
                nxt = res.back();
            } else {
                nxt = max(nums, i + 1, j + 1);
            }
            res.push_back(nxt);
        }
        return res;
    }

private:
    int max(const vector<int> &nums, int beg, int end) {
        int ret = INT_MIN;
        for (int i = beg; i < end; ++i)
            if (nums[i] > ret) ret = nums[i];
        return ret;
    }
};
