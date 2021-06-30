// 30ms, 36.44%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        if (nums.empty()) return false;
        unordered_map<int, int> tmp;
        for (int i = 0; i < nums.size(); ++i) {
            if (tmp.find(nums[i]) != tmp.end() && i - tmp[nums[i]] <= k) return true;
            tmp[nums[i]] = i;
        }
        return false;
    }
};
