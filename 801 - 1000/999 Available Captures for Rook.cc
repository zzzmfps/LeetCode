// 4ms, 100.00%; 8.6MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int numRookCaptures(const vector<vector<char>> &board) {
        int i = 0, j = 0;
        while (true) {
            if (board[i][j] == 'R') break;
            (j == 7) ? ++i, j = 0 : ++j;
        }
        int res = 0;
        for (int newi = i - 1; newi >= 0; --newi) {
            if (board[newi][j] == '.') continue;
            if (board[newi][j] == 'p') ++res;
            break;
        }
        for (int newi = i + 1; newi < 8; ++newi) {
            if (board[newi][j] == '.') continue;
            if (board[newi][j] == 'p') ++res;
            break;
        }
        for (int newj = j - 1; newj >= 0; --newj) {
            if (board[i][newj] == '.') continue;
            if (board[i][newj] == 'p') ++res;
            break;
        }
        for (int newj = j + 1; newj < 8; ++newj) {
            if (board[i][newj] == '.') continue;
            if (board[i][newj] == 'p') ++res;
            break;
        }
        return res;
    }
};
