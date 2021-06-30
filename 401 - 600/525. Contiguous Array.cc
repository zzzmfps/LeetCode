// 128ms, 54.14%; 26.7MB, 16.67%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(const vector<int> &nums) {
        int length = nums.size();
        int res = 0, record = 0;
        unordered_map<int, vector<int>> index;
        index[0].push_back(-1);
        for (int i = 0; i < length; ++i) {
            record += (nums[i] == 0 ? 1 : -1);
            auto &it = index[record];
            if (it.size() == 2) {
                it[1] = i;
            } else {
                it.push_back(i);
            }
        }
        if (record == 0) return length;
        for (const auto &idx : index) {
            const auto &v = idx.second;
            res = max(res, v.back() - v.front());
        }
        return res;
    }
};
