// 84ms, 99.15%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int fourSumCount(const vector<int> &A, const vector<int> &B, const vector<int> &C, const vector<int> &D) {
        unordered_map<int, int> ab(A.size() * B.size() * 2);
        for (const auto &a : A)
            for (const auto &b : B) ++ab[a + b];
        int result = 0;

        for (const auto &c : C)
            for (const auto &d : D) {
                auto iter = ab.find(-c - d);
                if (iter != ab.end()) result += iter->second;
            }

        return result;
    }
};
