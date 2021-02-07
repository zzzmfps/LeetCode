/* A TOTALLY STUPID PROBLEM. */
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// 0, specified for magic matrix(5 and 4, 3, 8, 1, 6, 7, 2, 9, or anti-clockwise)
// 8ms, 64.65%; 8.6MB, 100.0%
class Solution0 {
private:
    const string cw1 = "438167294381672";
    const string cw2 = "492761834927618";

public:
    int numMagicSquaresInside(vector<vector<int>> &grid) {
        int row = grid.size() - 1, col = grid[0].size() - 1;
        if (row < 2 || col < 2) return 0;
        int res = 0;
        for (int i = 1; i < row; ++i)
            for (int j = 1; j < col; ++j)
                if (grid[i][j] == 5 && check(grid, i, j)) ++res;
        return res;
    }

private:
    bool check(vector<vector<int>> &grid, int i, int j) {
        string tmp = "";
        for (int k = -1; k < 2; ++k) tmp += char(48 + grid[i - 1][j + k]);
        tmp += char(48 + grid[i][j + 1]);
        for (int k = -1; k < 2; ++k) tmp += char(48 + grid[i + 1][j - k]);
        tmp += char(48 + grid[i][j - 1]);
        return string::npos != cw1.find(tmp) || string::npos != cw2.find(tmp);
    }
};

// 1, normal solution, with some hardcode
// 8ms, 64.65%; 8.8MB, 100.0%
class Solution1 {
public:
    int numMagicSquaresInside(const vector<vector<int>> &grid) {
        int row = grid.size(), col = grid[0].size();
        if (row < 3 || col < 3) return 0;
        int res = 0;
        for (int i = 2; i < row; ++i)
            for (int j = 2; j < col; ++j)
                if (checkNums(grid, i, j) && checkSums(grid, i, j)) ++res;
        return res;
    }

private:
    bool checkNums(const vector<vector<int>> &grid, int i, int j) {
        bool *chk = new bool[10]();
        for (int k = 0; k < 3; ++k)
            for (int h = 0; h < 3; ++h) {
                int n = grid[i - k][j - h];
                if (n < 1 || n > 9 || chk[n]) return false;
                chk[n] = true;
            }
        return true;
    }

    bool checkSums(const vector<vector<int>> &grid, int i, int j) {
        int i1 = i - 1, i2 = i - 2, j1 = j - 1, j2 = j - 2;
        int cur = grid[i][j] + grid[i1][j1] + grid[i2][j2];
        if (15 != cur) return false;
        cur = grid[i2][j] + grid[i1][j1] + grid[i][j2];
        if (15 != cur) return false;
        cur = grid[i2][j2] + grid[i2][j1] + grid[i2][j];
        if (15 != cur) return false;
        cur = grid[i1][j2] + grid[i1][j1] + grid[i1][j];
        if (15 != cur) return false;
        cur = grid[i][j2] + grid[i][j1] + grid[i][j];
        if (15 != cur) return false;
        cur = grid[i2][j2] + grid[i1][j2] + grid[i][j2];
        if (15 != cur) return false;
        cur = grid[i2][j1] + grid[i1][j1] + grid[i][j1];
        if (15 != cur) return false;
        cur = grid[i2][j] + grid[i1][j] + grid[i][j];
        if (15 != cur) return false;
        return true;
    }
};
