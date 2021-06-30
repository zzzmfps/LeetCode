// 48ms, 99.82%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution {
public:
    vector<int> productExceptSelf(const vector<int> &nums) {
        int size = nums.size();
        vector<int> res(size, 1);
        for (int i = 1; i < size; ++i) res[i] = res[i - 1] * nums[i - 1];
        int right = 1;
        for (int i = size - 2; i >= 0; --i) {
            right *= nums[i + 1];
            res[i] *= right;
        }
        return res;
    }
};
