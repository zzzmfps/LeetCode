// 8 ms, 47.35%; 14.1 MB, 28.50%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(const vector<int> &nums, int target) {
        if (target == nums[0] || target == nums.back()) return true;
        if (target < nums[0] && target > nums.back()) return false;
        return this->helper(nums, target, 1, nums.size() - 1);
    }

private:
    bool helper(const vector<int> &nums, int target, size_t l, size_t r) {
        if (l >= r) return false;
        size_t mid = (l + r) >> 1;
        if (target == nums[mid]) return true;

        auto chkL = [&]() { return this->helper(nums, target, l, mid); };
        auto chkR = [&]() { return this->helper(nums, target, mid + 1, r); };

        if (nums[mid] == nums[0] && nums[mid] == nums.back()) return chkL() | chkR();
        if (nums[mid] == nums[0]) return chkR();
        if (nums[mid] == nums.back()) return chkL();
        if (nums[mid] > nums[0]) return (target > nums[0] && target < nums[mid]) ? chkL() : chkR();
        return (target > nums[mid] && target < nums.back()) ? chkR() : chkL();
    }
};
