// 6ms, 2.03%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            n &= n - 1;
            ++res;
        }
        return res;
    }
};
