// 32ms, 97.30%; 12.6MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(const string &s) {
        char clast = s[0] ^ 1, cur = s[0];
        int ilast = 0, icur = 0, res = 0;
        for (auto c : s) {
            if (c == cur) {
                ++icur;
            } else {
                res += min(ilast, icur);
                clast = cur, ilast = icur;
                cur = c, icur = 1;
            }
        }
        return res + min(ilast, icur);
    }
};
