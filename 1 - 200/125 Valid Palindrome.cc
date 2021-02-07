// 10ms, 20.37%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string tmp = "";
        for (auto x : s)
            if (x >= '0' && x <= '9' || x >= 'a' && x <= 'z')
                tmp += x;
            else if (x >= 'A' && x <= 'Z')
                tmp += tolower(x);
        if (tmp.empty() || tmp.length() == 1) return true;

        int end = tmp.length();
        int mid = end / 2;
        for (int i = 0; i < mid; ++i)
            if (tmp[i] != tmp[end - 1 - i]) return false;
        return true;
    }
};
