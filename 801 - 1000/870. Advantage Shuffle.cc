// 172ms, 73.39%; 21.5MB, 50.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> advantageCount(const vector<int> &A, const vector<int> &B) {
        vector<int> res(A.size());
        multiset<int> tmp(A.begin(), A.end());
        for (int i = 0, size = B.size(); i < size; ++i) {
            auto iter = tmp.upper_bound(B[i]);
            if (iter == tmp.end()) iter = tmp.begin();
            res[i] = *iter;
            tmp.erase(iter);
        }
        return res;
    }
};
