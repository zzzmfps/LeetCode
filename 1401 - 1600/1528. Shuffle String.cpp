// 12 ms, 69.87%; 15.4 MB, 88.63%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string restoreString(const string &s, const vector<int> &indices) const {
        string res(s.size(), ' ');
        for (int i = 0; i < s.size(); ++i) res[indices[i]] = s[i];
        return res;
    }
};
