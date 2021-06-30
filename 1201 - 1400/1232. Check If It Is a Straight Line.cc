// 12ms, 55.15%; 10.3MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStraightLine(const vector<vector<int>> &coordinates) {
        bool flag = true;
        if (coordinates[0][0] == coordinates[1][0]) {
            int x = coordinates[0][0];
            flag = all_of(coordinates.begin(), coordinates.end(), [x](const vector<int> &v) { return v[0] == x; });
        } else {
            int dx = coordinates[0][0], dy = coordinates[0][1];
            double slope = (coordinates[1][1] - dy) / double(coordinates[1][0] - dx);
            for (int i = 2, size = coordinates.size(); i < size; ++i) {
                double s2 = (coordinates[i][1] - dy) / double(coordinates[i][0] - dx);
                if (s2 == slope) continue;
                flag = false;
                break;
            }
        }
        return flag;
    }
};
