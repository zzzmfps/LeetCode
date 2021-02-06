// 0 ms, 100.00%; 8.3 MB, 96.73%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> createTargetArray(const vector<int> &nums, const vector<int> &index) {
        vector<int> target;
        target.reserve(nums.size());
        for (int i = 0; i < nums.size(); ++i) target.insert(target.begin() + index[i], nums[i]);
        return target;
    }
};
