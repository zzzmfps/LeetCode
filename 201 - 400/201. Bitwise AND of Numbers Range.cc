// 24ms, 98.51%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int diff = n - m, ret = 0;
        for (int i = 0, exp = 1; i < 31; ++i, exp <<= 1) {
            if (!(m & exp)) continue;
            if (diff < exp && (n & exp)) ret += exp;
        }
        return ret;
    }
};
