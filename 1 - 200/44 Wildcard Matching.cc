// 30ms, 83.04%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int idxS = 0, idxP = 0, star = -1, ss = 0;
        while (s[idxS])
            if (p[idxP] == '?' || s[idxS] == p[idxP])
                ++idxS, ++idxP;
            else if (p[idxP] == '*')
                star = idxP++, ss = idxS;
            else if (star >= 0)
                idxP = star + 1, idxS = ++ss;
            else
                return false;
        while (p[idxP] == '*') ++idxP;
        return p[idxP] == '\0';
    }
};
