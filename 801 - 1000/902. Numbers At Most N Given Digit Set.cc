// 4 ms, 44.91%; 8.3 MB, 65.87%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(const vector<string> &digits, int n) {
        string sn = to_string(n);
        vector<int> pows(sn.size());
        for (int i = 1; i < sn.size(); ++i) pows[i] = int(pow(digits.size(), i));

        vector<int> counts(sn.size());
        auto l = [&digits](char c) {
            int cnt = 0;
            while (cnt < digits.size() && digits[cnt][0] <= c) ++cnt;
            return cnt;
        };
        for (int i = sn.size() - 1, offset = 0; i > -1; --i) {
            int j = l(sn[i] - offset);
            if (j > 0) {
                counts[i] = j;
                offset = 0;
            } else if (i > 0) {
                counts[i] = digits.size();
                offset = 1;
            } else {
                counts[0] = 0;
            }
        }

        int res = accumulate(pows.begin(), pows.end(), 0);
        if (counts[0]) {
            for (int i = 0;; ++i) {
                if (i + 1 == counts.size()) {
                    res += counts[i];
                    break;
                }
                if (digits[counts[i] - 1][0] < sn[i]) {
                    res += counts[i] * pows[pows.size() - i - 1];
                    break;
                }
                res += (counts[i] - 1) * pows[pows.size() - i - 1];
            }
        }
        return res;
    }
};
