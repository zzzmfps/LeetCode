// 6ms, 66.91%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(const string &s, const string &t) {
        int m1[256]{0}, m2[256]{0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = m2[t[i]] = i + 1;
        }
        return true;
    }
};
