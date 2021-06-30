// 8ms, 99.85%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int triangleNumber(vector<int> &nums) {
        sort(nums.rbegin(), nums.rend());
        int res = 0, end = distance(nums.begin(), find(nums.begin(), nums.end(), 0)) - 1;
        for (int i = 0, r = end - 1; i < r; ++i) {
            int j = i + 1, k = end;
            while (j < k) {
                if (nums[j] + nums[k] > nums[i]) {
                    res += k - j;
                    j += 1;
                } else {
                    k -= 1;
                }
            }
        }
        return res;
    }
};
