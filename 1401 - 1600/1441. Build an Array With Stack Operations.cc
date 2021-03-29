// 0 ms, 100.00%; 7.8 MB, 68.04%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(const vector<int> &target, int n) {
        vector<string> res;
        for (int i = 0, v = 1; i < target.size(); ++v) {
            res.push_back("Push");
            if (target[i] > v) {
                res.push_back("Pop");
            } else if (target[i] == v) {
                ++i;
            }
        }
        return res;
    }
};
