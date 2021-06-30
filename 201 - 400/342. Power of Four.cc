// 6ms, 23.27%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && !(num & (num - 1)) && !(num & 0xAAAAAAAA);
    }
};
