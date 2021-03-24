// 0 ms, 100.00%; 8.4 MB, 95.05%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(const vector<int> &nums) {
        vector<int> sums(nums);
        for (size_t i = 1; i < sums.size(); ++i) sums[i] += sums[i - 1];
        return sums;
    }
};
