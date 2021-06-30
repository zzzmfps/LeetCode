// 0ms, 100.0%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long curMax = pow(2, 1 + int(log(n) / log(2)));
        while (n > 1) {
            n = curMax - n - 1;
            curMax >>= 1;
        }
        return n == 1 && curMax == 2;
    }
};
