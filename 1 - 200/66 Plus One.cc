// 4ms, 7.49%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> ans(digits);
        for (int i = ans.size() - 1; i >= 0; --i) {
            ans[i] = (ans[i] + 1) % 10;
            if (ans[i] != 0) break;
            if (i == 0) ans.insert(ans.cbegin(), 1);
        }
        return ans;
    }
};
