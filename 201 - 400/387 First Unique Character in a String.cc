// 56ms, 59.12%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string &s) const {
        int len = s.size();
        if (len) {
            if (len == 1) return 0;
            int count[26] {};
            char *s_ptr = &s[0], *s_end = s_ptr + len, *p = s_ptr;
            while (p < s_end) ++count[*p++ - 'a'];
            p = s_ptr;
            while (p < s_end) {
                if (count[*p - 'a'] == 1)
                    return int(p - s_ptr);
                ++p;
            }
        }
        return -1;
    }
};
