// 3ms, 97.87%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution {
public:
    bool rotateString(const string &A, const string &B) {
        if (A == B) return true;
        char beg = B[0];
        for (int i = 0; i < A.size(); ++i) {
            if (beg != A[i]) continue;
            if (B == string(A.cbegin() + i, A.cend()) + string(A.cbegin(), A.cbegin() + i)) return true;
        }
        return false;
    }
};
