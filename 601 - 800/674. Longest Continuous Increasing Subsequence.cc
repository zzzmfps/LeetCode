// 16ms, 56.70%; 9.3MB, 94.44%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(const vector<int> &nums) {
        int res = 0;
        int curLen = 0, last = -1;
        for (auto n : nums) {
            if (n > last) {
                curLen += 1;
                res = max(res, curLen);
            } else {
                curLen = 1;
            }
            last = n;
        }
        return max(res, curLen);
    }
};
