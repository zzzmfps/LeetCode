// 8ms, 52.50%; 8.6MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(const string &secret, const string &guess) {
        int res1 = 0, res2 = 0;
        int cnt1[10] = {}, cnt2[10] = {};
        for (int i = 0, size = secret.size(); i < size; ++i) {
            if (secret[i] == guess[i]) {
                res1 += 1;
            } else {
                cnt1[secret[i] - 48] += 1;
                cnt2[guess[i] - 48] += 1;
            }
        }
        for (int i = 0; i < 10; ++i) res2 += min(cnt1[i], cnt2[i]);
        return to_string(res1) + 'A' + to_string(res2) + 'B';
    }
};
