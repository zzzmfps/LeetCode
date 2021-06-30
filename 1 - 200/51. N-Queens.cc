// 5ms, 87.81%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution {
private:
    vector<vector<string>> res;
    bool *vertical, *ldiag, *rdiag;

public:
    vector<vector<string>> solveNQueens(int n) {
        vertical = new bool[n]();
        ldiag = new bool[2 * n - 1]();
        rdiag = new bool[2 * n - 1]();
        helper(vector<string>(), n);
        return res;
    }

private:
    void helper(vector<string> &&queen, int n) {
        int row = queen.size();
        if (row == n)
            res.push_back(queen);
        else
            for (int col = 0; col < n; ++col) {
                int lidx = row + col, ridx = row - col + n - 1;
                if (!vertical[col] && !ldiag[lidx] && !rdiag[ridx]) {
                    vertical[col] = ldiag[lidx] = rdiag[ridx] = true;
                    queen.push_back(string(col, '.') + 'Q' + string(n - col - 1, '.'));
                    helper(move(queen), n);
                    queen.pop_back();
                    vertical[col] = ldiag[lidx] = rdiag[ridx] = false;
                }
            }
    }
};
