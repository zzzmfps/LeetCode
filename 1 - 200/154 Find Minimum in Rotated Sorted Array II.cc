// 4ms, 100.0%; 8.9MB, 31.25%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums[0] == nums.back()) {
            auto it = find_if(nums.rbegin(), nums.rend(), [&](int x) { return x != nums[0]; });
            if (it == nums.rend()) return nums[0];
            nums.resize(distance(it, nums.rend()));
        }

        int length = nums.size();
        if (length == 1 || nums[0] < nums.back()) return nums[0];
        if (length == 2) return min(nums[0], nums[1]);
        if (nums[1] < nums[0] && nums[1] > nums.back()) return nums.back();

        int i = 0, j = length - 1;
        while (i < j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] >= nums[0]) {
                i = mid + 1;
            } else {
                j = mid;
            }
        }
        return nums[i];
    }
};
