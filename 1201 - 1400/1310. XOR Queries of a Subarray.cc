#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(const vector<int> &arr, const vector<vector<int>> &queries) {
        vector<int> xorAcc(arr.begin(), arr.end());
        for (int i = 1; i < xorAcc.size(); ++i) xorAcc[i] ^= xorAcc[i - 1];

        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int l = queries[i][0], r = queries[i][1];
            res[i] = (l == r ? arr[l] : xorAcc[r] ^ (0 == l ? 0 : xorAcc[l - 1]));
        }
        return res;
    }
};
