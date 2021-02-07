// 8ms, 63.90%; 8.8MB, 83.33%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int> &A) {
        vector<int> res;
        res.reserve(2 * A.size());
        for (int i = A.size() - 1; i > 0; --i) {
            if (A[i] == i + 1) continue;
            auto it = find(A.begin(), A.begin() + i + 1, i + 1);
            int diff = distance(A.begin(), it);
            if (diff > 0) {
                reverse(A.begin(), it + 1);
                res.push_back(diff + 1);
            }
            reverse(A.begin(), A.begin() + i + 1);
            res.push_back(i + 1);
        }
        res.shrink_to_fit();
        return res;
    }
};
