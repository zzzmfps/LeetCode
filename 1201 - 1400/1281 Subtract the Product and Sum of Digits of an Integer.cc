// 0ms, 100.00%; 8.3MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        string num = to_string(n);
        int x = 1, y = 0;
        for (auto v : num) x *= (v - 48), y += (v - 48);
        return x - y;
    }
};
