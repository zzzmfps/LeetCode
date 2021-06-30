// 48ms, 94.85%; 12.4MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(const string &s) {
        if (s[0] == 48) return 0;
        long long n2 = 1, n1 = (s[0] == 42 ? 9 : 1), n0 = 0;
        for (int i = 1, size = s.size(); i < size; ++i) {
            n0 += n1 * (s[i] == 42 ? 9 : s[i] == 48 ? 0 : 1);
            if (s[i - 1] == 42 && s[i] == 42) {
                n0 += n2 * 15;
            } else if (s[i - 1] == 42) {
                n0 += n2 * (s[i] > 54 && s[i] < 58 ? 1 : 2);
            } else if (s[i] == 42) {
                if (s[i - 1] == 49) {
                    n0 += n2 * 9;
                } else if (s[i - 1] == 50) {
                    n0 += n2 * 6;
                }
            } else {
                int v = 10 * s[i - 1] + s[i] - 528;
                if (v > 9 && v < 27) n0 += n2;
            }
            n0 %= 1000000007;
            n2 = n1, n1 = n0, n0 = 0;
        }
        return n1;
    }
};
