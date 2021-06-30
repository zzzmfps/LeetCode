// 35ms, 43.98%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        return int((sqrt(1 + 8 * double(n)) - 1) / 2);
    }
};
