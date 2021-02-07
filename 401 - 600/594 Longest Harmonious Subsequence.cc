// 104ms, 54.50%; 20.6MB, 33.33%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLHS(const vector<int> &nums) {
        if (nums.empty()) return 0;
        map<int, int> tmp;
        for (auto n : nums) ++tmp[n];
        int res = 0;
        for (auto it = next(tmp.begin()); it != tmp.end(); ++it) {
            if (prev(it)->first + 1 < it->first) continue;
            res = max(res, prev(it)->second + it->second);
        }
        return res;
    }
};
