// 4ms, 72.47%; 8.2MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if (n & 1) {
            int tmp = (n - 1) / 2;
            return 2 + min(integerReplacement(tmp), integerReplacement(tmp + 1));
        } else {
            return 1 + integerReplacement(n / 2);
        }
    }
};
