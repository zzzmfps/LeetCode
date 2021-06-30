// 12ms, 85.14%; 10.8MB, 78.57%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(const vector<int> &A) {
        int size = A.size();
        vector<bool> res;
        res.resize(size);
        if (A[0] == 0) res[0] = true;
        for (int i = 1, cur = A[0] % 5; i < size; ++i) {
            cur = ((cur << 1) + A[i]) % 5;
            if (cur == 0) res[i] = true;
        }
        return res;
    }
};
