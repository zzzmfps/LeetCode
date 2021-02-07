// 4ms, 19.76%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0;
        int i = a.size() - 1, j = b.size() - 1;
        string s = "";
        while (i >= 0 || j >= 0 || c == 1) {
            c += i >= 0 ? a[i--] - '0' : 0;
            c += j >= 0 ? b[j--] - '0' : 0;
            s += c % 2 + '0';
            c /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
