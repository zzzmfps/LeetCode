// 4ms, 100.0%; 8.2MB, 100.0%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int n = (1 + sqrt(8) * sqrt(target)) / 2;
        int acc = n * (n + 1) / 2;
        while (acc < target || (acc - target) & 1) ++n, acc += n;
        return n;
    }
};
