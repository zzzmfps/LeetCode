// 12ms
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(const string &S, const char C) {
        int size = S.size(), last = -1;
        vector<int> res(size);
        for (int i = 0; i < size; ++i) {
            if (S[i] != C) continue;
            if (last < 0)
                iota(res.rend() - i, res.rend(), 1);
            else {
                int tmp = (i + last) / 2;
                iota(res.begin() + last, res.begin() + tmp, 1);
                iota(res.rend() - i, res.rend() - tmp, 1);
            }
            last = i + 1;
        }
        iota(res.begin() + last, res.end(), 1);
        return res;
    }
};
