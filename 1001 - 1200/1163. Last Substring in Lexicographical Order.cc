// 48 ms, 64.62%; 16.6 MB, 96.41%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lastSubstring(const string &s) {
        size_t idx = 0, cur = 1;
        while (cur < s.size()) {
            if (s[idx] != s[cur]) {
                if (s[idx] < s[cur]) idx = cur;
                ++cur;
                continue;
            }
            size_t idx2 = idx + 1, cur2 = cur + 1;
            while (cur2 < s.size()) {
                if (s[idx2] != s[cur2]) {
                    if (s[idx2] < s[cur2]) idx = cur;
                    break;
                }
                ++idx2, ++cur2;
            }
            cur = (idx == cur ? max(idx + 1, cur2 - 1) : cur2);
        }
        return s.substr(idx);
    }
};
