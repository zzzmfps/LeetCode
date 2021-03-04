// 4 ms, 90.89%; 10.9 MB, 81.78%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(const vector<vector<int>> &queens, const vector<int> &king) {
        vector<int> marks(8, -1);
        int _diff = king[0] - king[1], _sum = king[0] + king[1];
        for (int i = 0; i < queens.size(); ++i) {
            int x = queens[i][0], y = queens[i][1];
            if (x == king[0]) {
                if (y < king[1]) {
                    if (marks[0] < 0 || queens[marks[0]][1] < y) marks[0] = i;
                } else {
                    if (marks[1] < 0 || queens[marks[1]][1] > y) marks[1] = i;
                }
            } else if (y == king[1]) {
                if (x < king[0]) {
                    if (marks[2] < 0 || queens[marks[2]][0] < x) marks[2] = i;
                } else {
                    if (marks[3] < 0 || queens[marks[3]][0] > x) marks[3] = i;
                }
            } else if (x - y == _diff) {
                if (x < king[0]) {
                    if (marks[4] < 0 || queens[marks[4]][0] < x) marks[4] = i;
                } else {
                    if (marks[5] < 0 || queens[marks[5]][0] > x) marks[5] = i;
                }
            } else if (x + y == _sum) {
                if (y < king[1]) {
                    if (marks[6] < 0 || queens[marks[6]][1] < y) marks[6] = i;
                } else {
                    if (marks[7] < 0 || queens[marks[7]][1] > y) marks[7] = i;
                }
            }
        }
        vector<vector<int>> res;
        for (int i = 0; i < 8; ++i)
            if (marks[i] != -1) res.push_back(queens[marks[i]]);
        return res;
    }
};
