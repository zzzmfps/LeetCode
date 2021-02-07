// 56ms, 95.49%; 15.4MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(const string &s, const string &t) {
        int idx = 0;
        for (auto c : s) {
            int tmp = t.find(c, idx);
            if (tmp == string::npos) return false;
            idx = tmp + 1;
        }
        return true;
    }
};
