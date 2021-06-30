// 48ms, 94.53%; 11MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(const vector<int> &arr) {
        vector<int> res(arr.begin(), arr.end() - 1);
        res.push_back(-1);
        for (int i = arr.size() - 1; i > 0; --i) res[i - 1] = max(res[i], arr[i]);
        return res;
    }
};
