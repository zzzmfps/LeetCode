// 5ms, 27.07%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s.front() == '0') return 0;
        // r2: decode ways of s[: i - 1] , r1: s[: i]
        int r1 = 1, r2 = 1, size = s.size();
        for (int i = 1; i < size; ++i) {
            if (s[i] == '0') r1 = 0;
            if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
                r1 = r2 + r1; // sum of r1 and r2
                r2 = r1 - r2; // old r1
            } else
                r2 = r1;
        }
        return r1;
    }
};
