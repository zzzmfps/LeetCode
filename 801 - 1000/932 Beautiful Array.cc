// 12ms, 77.73%; 12.8MB, 17.39%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> res;
        res.resize(N);
        iota(res.begin(), res.end(), 1);
        partition(res, 0, N);
        return res;
    }

private:
    void partition(vector<int> &v, int i, int j) {
        if (j - i < 3) return;
        int k = (i + j + 1) >> 1;
        vector<int> tmp(j - k);
        for (int idx = i + 1, ins = 0; idx < j; idx += 2) tmp[ins++] = v[idx];
        for (int idx = i + 2, ins = i + 1; idx < j; idx += 2) v[ins++] = v[idx];
        copy(tmp.begin(), tmp.end(), v.begin() + k);
        partition(v, i, k);
        partition(v, k, j);
    }
};
