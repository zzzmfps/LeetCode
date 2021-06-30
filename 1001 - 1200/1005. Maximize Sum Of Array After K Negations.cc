// 4ms, 98.04%; 9.2MB, 7.14%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(const vector<int> &A, int K) {
        multiset<int> tmp;
        int res = 0, _min = 0x7FFFFFFF;
        for (auto x : A) {
            res += x;
            if (x <= 0) tmp.insert(x);
            _min = min(_min, abs(x));
        }
        if (tmp.size() >= K) {
            auto it = tmp.begin();
            for (int i = 0; i < K; ++i) {
                res -= 2 * (*it);
                ++it;
            }
        } else {
            int x = K - tmp.size();
            auto it = tmp.begin();
            while (it != tmp.end()) {
                res -= 2 * (*it);
                ++it;
            }
            if (x & 1) res -= 2 * _min;
        }
        return res;
    }
};
