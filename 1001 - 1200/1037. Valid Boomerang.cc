// 4ms, 64.84%; 8.3MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBoomerang(const vector<vector<int>> &points) {
        int x1 = points[0][0] - points[1][0], y1 = points[0][1] - points[1][1];
        int x2 = points[0][0] - points[2][0], y2 = points[0][1] - points[2][1];
        return x1 * y2 != x2 * y1;
    }
};
