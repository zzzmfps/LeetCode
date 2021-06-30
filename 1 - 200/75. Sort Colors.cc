// 4ms, 100.0%; 8.8MB, 5.31%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    void sortColors(vector<int> &nums) {
        if (nums.size() < 2) return;
        int index;
        index = findFirstIndex(nums, 0);
        index = sortColor(nums, 0, 1 + index);
        index = findFirstIndex(nums, 1, index);
        sortColor(nums, 1, 1 + index);
    }

private:
    int findFirstIndex(const vector<int> &nums, int n, int hint = 0) {
        for (int size = nums.size(); hint < size; ++hint)
            if (nums[hint] != n) break;
        return hint;
    }

    int sortColor(vector<int> &nums, int n, int index, int delta = 1) {
        for (int size = nums.size(); index < size; ++index) {
            if (nums[index] != n) {
                ++delta;
            } else {
                swap(nums[index], nums[index - delta]);
            }
        }
        return index - delta;
    }
};
