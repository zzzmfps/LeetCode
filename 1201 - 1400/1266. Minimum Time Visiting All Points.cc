// 4ms, 99.33%; 9.6MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(const vector<vector<int>> &points) {
        int res = 0;
        for (int i = 1; i < points.size(); ++i)
            res += max(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1]));
        return res;
    }
};
