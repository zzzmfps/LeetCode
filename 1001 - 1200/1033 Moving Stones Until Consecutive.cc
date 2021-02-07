// 0ms, 100.00%; 8.3MB, 90.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        if (a > b) swap(a, b);
        if (a > c) swap(a, c);
        if (b > c) swap(b, c);
        int diff1 = b - a, diff2 = c - b, diff3 = c - a - 2;
        int left = (diff3 == 0 ? 0 : diff1 < 3 || diff2 < 3 ? 1 : 2);
        return vector<int>{left, diff3};
    }
};
