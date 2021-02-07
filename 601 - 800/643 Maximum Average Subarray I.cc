// 176ms, 67.29%; 16.8MB, 33.33%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(const vector<int> &nums, int k) {
        int _sum = accumulate(nums.begin(), nums.begin() + k, 0), _max = _sum;
        for (int i = k; i < nums.size(); ++i) {
            _sum += nums[i] - nums[i - k];
            _max = max(_max, _sum);
        }
        return _max / double(k);
    }
};
