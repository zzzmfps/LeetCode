// 4 ms, 88.09%; 11.5 MB, 87.25%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(const vector<string> &word1, const vector<string> &word2) const {
        int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
        while (x1 < word1.size() && x2 < word2.size()) {
            if (word1[x1][y1] != word2[x2][y2]) return false;
            y1 = (1 + y1) % word1[x1].size();
            y2 = (1 + y2) % word2[x2].size();
            if (0 == y1) ++x1;
            if (0 == y2) ++x2;
        }
        return x1 == word1.size() && x2 == word2.size();
    }
};
