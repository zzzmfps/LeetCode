#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// 0, in place: 24ms, 100.00%; 9.8MB, 99.04%
class Solution0 {
public:
    vector<int> sortArrayByParity(vector<int> &A) {
        int i = 0, j = A.size() - 1;
        while (i < j) {
            int a = A[i] & 1, b = A[j] & 1;
            if (a != b) {
                if (a == 1) swap(A[i], A[j]);
                ++i, --j;
            } else {
                (a == 0) ? ++i : --j;
            }
        }
        return A;
    }
};

// 1, create a new vector: 24ms, 100.00%; 9.7MB, 99.36%
class Solution1 {
public:
    vector<int> sortArrayByParity(const vector<int> &A) {
        vector<int> res(A.size());
        int i = 0, j = A.size() - 1;
        for (auto n : A) {
            if (n & 1) {
                res[j--] = n;
            } else {
                res[i++] = n;
            }
        }
        return res;
    }
};
