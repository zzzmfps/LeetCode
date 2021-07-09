// 0 ms, 100.00%; 6.1 MB, 73.86%
#include <bits/stdc++.h>
using namespace std;

/**
 * direction - number back to start
 *     North - 1, or never
 *     South - 1, 2
 *     East/West - 1, 4
 */

class Solution {
public:
    bool isRobotBounded(const string &instructions) {
        char dir = 0; // 0: North, 1: East, 2: South, 3: West
        int x = 0, y = 0;
        for (auto &&i : instructions) {
            switch (i) {
                case 'L': dir = (dir + 3) % 4; break;
                case 'R': dir = (dir + 1) % 4; break;
                default: (dir & 1 ? x : y) += (dir < 2 ? 1 : -1);
            }
        }
        return 0 != dir || (0 == x && 0 == y);
    }
};
