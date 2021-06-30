// 4ms, 49.26%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(const string &s) {
        vector<string> res;
        if (s.empty() || s.size() < 4) return res;
        for (int a = 1; a < 4; ++a) {
            string A = string(s.begin(), s.begin() + a);
            if (!check(A)) continue;
            for (int b = a + 1; b < a + 4; ++b) {
                string B = string(s.begin() + a, s.begin() + b);
                if (!check(B)) continue;
                for (int c = b + 1; c < b + 4; ++c) {
                    string C = string(s.begin() + b, s.begin() + c);
                    if (!check(C)) continue;

                    int d = s.size();
                    if (d <= c) break;
                    if (d - c > 3) continue;
                    string D = string(s.begin() + c, s.begin() + d);
                    if (!check(D)) continue;

                    res.push_back(A + "." + B + "." + C + "." + D);
                }
            }
        }
        return res;
    }

private:
    bool check(const string &n) {
        if (n.empty()) return false;
        if (n.size() == 1) return true;
        if (n[0] == '0') return false;
        if (stoi(n) > 255) return false;
        return true;
    }
};
