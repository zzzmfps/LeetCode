// 32ms, 99.80%; 16.1MB, 91.89%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string findLongestWord(const string &s, vector<string> &d) {
        sort(d.begin(), d.end(),
             [](const auto &x, const auto &y) { return x.size() > y.size() || x.size() == y.size() && x < y; });
        for (const auto &w : d)
            if (check(s, w)) return w;
        return "";
    }

private:
    bool check(const string &origin, const string &word) {
        int end1 = origin.size(), end2 = word.size();
        int beg1 = 0, beg2 = 0;
        while (beg1 < end1 && beg2 < end2)
            if (origin[beg1++] == word[beg2]) ++beg2;
        return beg2 == end2;
    }
};
