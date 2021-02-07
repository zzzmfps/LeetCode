// 11ms, 18.66%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int index = s.size() - 1;
        string res = "";
        while (index >= 0) res += s[index--];
        return res;
    }
};
