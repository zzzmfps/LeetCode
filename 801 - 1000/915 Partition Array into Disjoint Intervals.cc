// 12ms, 99.16%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int partitionDisjoint(vector<int> &A) {
        int size = A.size();
        vector<int> mins;
        mins.resize(size);
        mins.back() = A.back();
        for (int i = size - 2; i >= 0; --i) mins[i] = min(mins[i + 1], A[i]);
        int maxn = A.front();
        for (int i = 1; i < size; ++i) {
            if (maxn <= mins[i]) return i;
            maxn = max(maxn, A[i]);
        }
    }
};
