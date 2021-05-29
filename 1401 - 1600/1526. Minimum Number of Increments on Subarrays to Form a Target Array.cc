// 120 ms, 52.77%; 73.1 MB, 58.09%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberOperations(const vector<int> &target) {
        int res = 0;

        bool increasing = true;
        int cur = 0;
        for (size_t i = 0; i < target.size(); ++i) {
            if (increasing) {
                if (target[i] >= cur) {
                    res += target[i] - cur;
                } else {
                    increasing = false;
                }
            } else if (target[i] > cur) {
                res += target[i] - cur;
                increasing = true;
            }
            cur = target[i];
        }

        return res;
    }
};
