// 12 ms, 74.13%; 7.6 MB, 99.74%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeCircle(const string &moves) {
        int counts[4] = {};
        for (auto &&c : moves) ++counts[this->toIndex(c)];
        return counts[0] == counts[1] && counts[2] == counts[3];
    }

private:
    unsigned toIndex(char c) {
        switch (c) {
        case 'U': return 0;
        case 'D': return 1;
        case 'L': return 2;
        case 'R': return 3;
        }
        return 4;
    }
};
