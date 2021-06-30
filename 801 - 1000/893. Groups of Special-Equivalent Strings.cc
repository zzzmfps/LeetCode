// 12ms, 70.46%; 10.4MB, 50.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(const vector<string> &A) {
        unordered_set<string> tmp;
        for (const auto &a : A) {
            vector<string> p(2, "");
            for (int i = 0, length = a.size(); i < length; ++i) p[i & 1] += a[i];
            sort(p[0].begin(), p[0].end());
            sort(p[1].begin(), p[1].end());
            tmp.insert(p[0] + ' ' + p[1]);
        }
        return tmp.size();
    }
};
