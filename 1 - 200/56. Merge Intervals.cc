// 14ms, 35.40%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(const vector<vector<int>> &intervals) {
        if (intervals.empty()) return vector<vector<int>>{};
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back().back() < intervals[i].front()) {
                res.push_back(intervals[i]);
            } else {
                res.back().back() = max(res.back().back(), intervals[i].back());
            }
        }
        return res;
    }
};
