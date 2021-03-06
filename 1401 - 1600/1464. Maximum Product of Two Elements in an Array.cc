// 8 ms, 85.97 %; 10.2 MB, 96.67 %
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(const vector<int> &nums) const {
        int x1 = 0, x2 = 0;
        for (auto n : nums) {
            if (n > x1) {
                x1 = n;
                if (x1 > x2) swap(x1, x2);
            }
        }
        return (x1 - 1) * (x2 - 1);
    }
};
