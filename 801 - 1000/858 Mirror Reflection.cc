// 0ms, 100.0%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorReflection(int p, int q) {
        while (!(p & 1 || q & 1)) p >>= 1, q >>= 1;
        return 1 - (p & 1) + (q & 1);
    }
};
