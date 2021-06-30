// 4ms, 62.63%; 8.5MB, 72.73%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(const string &S, const string &T) { // simple simulation
        int p1 = S.size() - 1, p2 = T.size() - 1;
        int cnt1 = 0, cnt2 = 0;
        while (true) {
            // to reach where cannot backspace anymore
            while (p1 > -1 && (cnt1 || S[p1] == '#')) cnt1 += (S[p1--] == '#' ? 1 : -1);
            while (p2 > -1 && (cnt2 || T[p2] == '#')) cnt2 += (T[p2--] == '#' ? 1 : -1);
            // two strings completed check at the same time, or not
            if (p1 < 0 && p2 >= 0 || p2 < 0 && p1 >= 0) return false;
            if (p1 < 0) break;
            if (S[p1--] != T[p2--]) return false; // find different chars
        }
        return true;
    }
};
