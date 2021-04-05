// 0 ms, 100.00%; 8.7 MB, 99.30%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minOperations(const string &boxes) {
        vector<int> res(boxes.size());
        for (int i = 1, n = 0, v = 0; i < boxes.size(); ++i) {
            n += boxes[i - 1] - 48;
            v += n;
            res[i] += v;
        }
        for (int i = boxes.size() - 2, n = 0, v = 0; i > -1; --i) {
            n += boxes[i + 1] - 48;
            v += n;
            res[i] += v;
        }
        return res;
    }
};
