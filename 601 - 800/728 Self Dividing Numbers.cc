// 4ms, 100.0%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left, n; i <= right; ++i) {
            for (n = i; n > 0; n /= 10) {
                int r = n % 10;
                if (r == 0 || i % r != 0) break;
            }
            if (n == 0) res.push_back(i);
        }
        return res;
    }
};
