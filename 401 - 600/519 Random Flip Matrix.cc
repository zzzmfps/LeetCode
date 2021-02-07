// 20ms, 100.0%; 12.3MB, 94.44%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
private:
    int col, maxLength;
    unordered_set<int> pts;

public:
    Solution(int n_rows, int n_cols) : col(n_cols), maxLength(n_rows * n_cols) {}

    vector<int> flip() {
        int opt;
        do {
            opt = rand() % maxLength;
        } while (pts.find(opt) != pts.end());
        pts.insert(opt);
        return vector<int>{opt / col, opt % col};
    }

    void reset() {
        pts.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj.flip();
 * obj.reset();
 */
