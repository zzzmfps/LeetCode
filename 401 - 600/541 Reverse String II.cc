// 8ms, 67.65%; 10.4MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseStr(const string &s, int k) {
        string res = "";
        for (int i = 0, size = s.size(); i < size; i += k) // just simulation
            res += ((i / k) & 1 ? s.substr(i, k) : string(s.rend() - min(i + k, size), s.rend() - i));
        return res;
    }
};
