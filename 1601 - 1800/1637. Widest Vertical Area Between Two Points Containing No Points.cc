// 356 ms, 16.40%; 81.2 MB, 19.85%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(const vector<vector<int>> &points) {
        set<int> x;
        for (auto &&p : points) x.insert(p[0]);

        int res = 0;
        for (auto it = next(x.begin()); it != x.end(); ++it) res = max(res, *it - *prev(it));
        return res;
    }
};
