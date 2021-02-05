// 0 ms, 100.00%; 6.1 MB, 71.89%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(const string &s) {
        int left = 0, ast = 0, used = 0;
        for (int i = 0; i < s.size(); ++i) {
            if ('(' == s[i]) {
                ++left;
            } else if ('*' == s[i]) {
                if (left > 0) {
                    --left, ++used;
                } else {
                    ++ast;
                }
            } else {
                if (left > 0) {
                    --left;
                } else if (used > 0) {
                    --used, ++ast;
                } else if (ast > 0) {
                    --ast;
                } else {
                    return false;
                }
            }
        }
        return 0 == left;
    }
};
