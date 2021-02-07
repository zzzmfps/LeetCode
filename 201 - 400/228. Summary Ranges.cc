// 0 ms, 100.00%; 6.8 MB, 79.32%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(const vector<int> &nums) {
        vector<string> res;
        if (nums.empty()) return res;

        int begin = nums[0], last = nums[0];
        auto getRange = [&begin, &last]() {
            string range = to_string(begin);
            if (begin != last) range += "->" + to_string(last);
            return range;
        };

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == 1 + last) {
                last = nums[i];
                continue;
            }
            res.push_back(getRange());
            begin = last = nums[i];
        }
        res.push_back(getRange());
        return res;
    }
};
