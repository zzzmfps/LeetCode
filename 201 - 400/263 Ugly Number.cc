// 4ms, 21.06%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num == 0) return false;
        int ugly_factors[] = {2, 3, 5};
        for (auto x : ugly_factors)
            while (num % x == 0) num /= x;
        return num == 1 ? true : false;
    }
};
