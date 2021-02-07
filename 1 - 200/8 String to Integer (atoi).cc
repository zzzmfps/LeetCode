// 28ms, 17.50%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0; // empty
        int beg = 0;
        for (; beg < str.length(); ++beg)
            if (str[beg] != ' ') break;
        if (beg == str.length()) return 0; // only whitespaces
        string test = "0123456789+-";
        int isSignNum = test.find(str[beg]);
        int isSign = test.find(str[beg], 10);
        if (isSignNum == string::npos) return 0;                         // other characters
        if (beg + 1 == str.length() && isSign != string::npos) return 0; // only single +/-

        bool positive = true;
        if (isSign != string::npos) // 1-bit num or more bits num with optional +/-
        {
            if (isSign == 11) positive = false;
            ++beg;
        }
        str = str.substr(beg);
        long ans = 0;
        for (auto x : str)
            if (x >= '0' && x <= '9') {
                ans = ans * 10 + long(x - '0');
                if (ans < INT_MIN || ans > INT_MAX) return (positive ? INT_MAX : INT_MIN);
            } else
                break;
        return ans * (positive ? 1 : -1);
    }
};
