// 16 ms, 78.57%; 35 MB, 11.90%
#include <bits/stdc++.h>
using namespace std;

static constexpr int EXPS[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536};

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int num = 1 << n;

        bool *used = new bool[num]{};
        used[start] = true;
        vector<int> res(num);
        res[0] = start;

        this->dfs(res, used, n, num - 1);

        delete[] used;
        return res;
    }

private:
    bool dfs(vector<int> &res, bool *used, int n, int left) {
        if (!left) {
            int x = res[0], y = res[1];
            return binary_search(EXPS, EXPS + 17, x ^ y);
        }
        int x = res[(1 + left) % static_cast<int>(res.size())];
        for (int i = 0, mask = 1; i < n; ++i, mask <<= 1) {
            int y = x ^ mask;
            if (used[y]) continue;
            res[left] = y;
            used[y] = true;
            if (this->dfs(res, used, n, left - 1)) return true;
            used[y] = false;
        }
        return false;
    }
};
