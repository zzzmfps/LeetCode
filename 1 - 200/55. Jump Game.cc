// 14ms, 24.20%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(const vector<int> &nums) {
        int i = 0, n = nums.size();
        for (int reach = 0; i < n && i <= reach; ++i) reach = max(i + nums[i], reach);
        return i == n;
    }
};
