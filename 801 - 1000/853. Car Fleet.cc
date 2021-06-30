// 44ms, 94.90%; 10.8MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, const vector<int> &position, const vector<int> &speed) {
        vector<pair<int, int>> tmp(position.size());
        for (int i = 0, size = tmp.size(); i < size; ++i) tmp[i].first = position[i], tmp[i].second = speed[i];
        sort(tmp.begin(), tmp.end(), [](const auto &x, const auto &y) { return x.first > y.first; });
        int res = 0;
        double last = 0.0;
        for (int i = 0, size = tmp.size(); i < size; ++i) {
            double time = double(target - tmp[i].first) / tmp[i].second;
            if (time > last) {
                res += 1;
                last = time;
            }
        }
        return res;
    }
};
