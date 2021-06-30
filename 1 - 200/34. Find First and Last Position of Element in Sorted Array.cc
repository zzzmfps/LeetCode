// 11ms, 28.83%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.empty()) return vector<int>{-1, -1};
        int beg = 0, end = nums.size() - 1;
        if (nums[beg] > target || nums[end] < target) return vector<int>{-1, -1};

        while (beg <= end) {
            int mid = (beg + end) / 2;
            if (nums[mid] < target)
                beg = mid + 1;
            else if (nums[mid] > target)
                end = mid - 1;
            else {
                beg = mid;
                while (beg > 0 && nums[beg - 1] == nums[mid]) --beg;
                while (mid < end && nums[mid + 1] == nums[beg]) ++mid;
                return vector<int>{beg, mid};
            }
        }
        return vector<int>{-1, -1};
    }
};
