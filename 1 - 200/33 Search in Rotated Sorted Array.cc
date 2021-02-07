// 7ms, 29.85%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        if (nums.empty()) return -1;
        int n = nums.size() - 1, trav;
        if (target >= nums[0]) {
            trav = 0;
            while (target > nums[trav]) ++trav;
        } else if (target <= nums[n]) {
            trav = n;
            while (target < nums[trav]) --trav;
        } else
            return -1;
        return target == nums[trav] ? trav : -1;
    }
};
