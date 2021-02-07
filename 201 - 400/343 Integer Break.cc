// 2ms, 100.0%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int integerBreak(int n) {
        // brute force, another method refers to Python3 code.
        int maxProduct = 1;
        for (int i = max(2, int(sqrt(n))); i < max(3, (n + 1) / 2); ++i) {
            int num = n / i, cur = num;
            int tmp1 = n % i, tmp2 = i - tmp1 - 1;
            while (tmp1--) cur *= num + 1;
            while (tmp2--) cur *= num;
            maxProduct = max(maxProduct, cur);
        }
        return maxProduct;
    }
};
