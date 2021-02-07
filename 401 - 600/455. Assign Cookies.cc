// 20 ms, 99.44%; 17.4 MB, 87.39%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0;
        for (int j = 0; i < g.size() && j < s.size(); ++j) {
            while (j < s.size() && s[j] < g[i]) ++j;
            if (j == s.size()) break;
            ++i;
        }
        return i;
    }
};
