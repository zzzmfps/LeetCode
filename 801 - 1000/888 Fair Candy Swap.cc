// 92ms, 95.91%; 20.6MB, 50.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(const vector<int> &A, const vector<int> &B) {
        int diff = (accumulate(A.begin(), A.end(), 0) - accumulate(B.begin(), B.end(), 0)) >> 1;
        bool *tmp = new bool[100001]{};
        for (auto a : A) tmp[a] = true;
        for (auto b : B) {
            int aa = b + diff;
            if (aa > 0 && aa < 100001 && tmp[aa]) {
                delete[] tmp;
                return vector<int>{aa, b};
            }
        }
        return vector<int>();
    }
};
