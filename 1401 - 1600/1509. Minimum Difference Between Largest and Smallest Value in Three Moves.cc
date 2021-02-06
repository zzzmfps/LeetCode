// 76 ms, 99.30%; 35.2 MB, 95.10%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDifference(const vector<int> &nums) {
        if (nums.size() < 5) return 0;

        priority_queue<int, vector<int>, less<int>> mins;
        priority_queue<int, vector<int>, greater<int>> maxs;
        for (auto &&n : nums) {
            if (mins.size() < 4 || n < mins.top()) {
                if (4 == mins.size()) mins.pop();
                mins.push(n);
            }
            if (maxs.size() < 4 || n > maxs.top()) {
                if (4 == maxs.size()) maxs.pop();
                maxs.push(n);
            }
        }

        vector<int> mins_, maxs_;
        while (!mins.empty()) mins_.push_back(mins.top()), mins.pop();
        while (!maxs.empty()) maxs_.push_back(maxs.top()), maxs.pop();
        int diffs[] = {maxs_[3] - mins_[0], maxs_[2] - mins_[1], maxs_[1] - mins_[2], maxs_[0] - mins_[3]};
        int minDiff = diffs[0];
        for (int i = 1; i < 4; ++i)
            if (diffs[i] < minDiff) minDiff = diffs[i];
        return minDiff;
    }
};
