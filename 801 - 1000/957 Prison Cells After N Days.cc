// 0ms, 100.00%; 8.5MB, 78.85%
#include <bits/stdc++.h>
using namespace std;

auto x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int> cells, int N) {
        if ((N %= 14) == 0) N = 14;
        for (int i = 0; i < N; ++i) {
            vector<int> tmp(8, 0);
            for (int j = 1; j < 7; ++j) tmp[j] = (cells[j - 1] == cells[j + 1]);
            cells.swap(tmp);
        }
        return cells;
    }
};
