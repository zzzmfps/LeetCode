// 4ms, 100.00%; 8.5MB, 98.81%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int numJewelsInStones(const string &j, const string &s) {
        auto getIndex = [](char c) { return c >= 'a' ? c - 71 : c - 65; };
        bool alphabet[52] = {};
        for (auto c : j) alphabet[getIndex(c)] = true;
        int ret = 0;
        for (auto c : s)
            if (alphabet[getIndex(c)]) ret += 1;
        return ret;
    }
};
