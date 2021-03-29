// 36 ms, 99.30%; 15.3 MB, 99.30%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(const string &s, int k) {
        int num = static_cast<int>(pow(2, k));
        if (s.size() < k - 1 + num) return false;

        int mask = (num - 1) >> 1, val = 0;
        for (int i = 0; i < k - 1; ++i) val = (val << 1) | (s[i] - 48);

        bool *rec = new bool[num]{};
        for (int i = k - 1; i < s.size(); ++i) {
            val = ((val & mask) << 1) | (s[i] - 48);
            if (!rec[val] && 0 == --num) return true;
            rec[val] = true;
        }
        delete[] rec;
        return false;
    }
};
