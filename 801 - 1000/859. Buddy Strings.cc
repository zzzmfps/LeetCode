// 4 ms, 82.66%; 6.8 MB, 94.66%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool buddyStrings(const string &A, const string &B) {
        if (A.size() != B.size()) return false;
        int i, j = -1, cnt = 0;
        for (int k = 0; k < A.size(); ++k) {
            if (A[k] == B[k]) continue;
            i = j, j = k, ++cnt;
        }
        if (0 == cnt) return A.size() != set<char>(A.begin(), A.end()).size();
        if (2 == cnt) return A[i] == B[j] && A[j] == B[i];
        return false;
    }
};
