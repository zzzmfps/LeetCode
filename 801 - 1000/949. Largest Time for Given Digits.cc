// 0ms, 100.0%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string largestTimeFromDigits(vector<int> &A) {
        sort(A.rbegin(), A.rend());
        if (A[3] > 2 || A[3] == 2 && (A[2] > 3 || A[1] > 5) || A[3] != 2 && A[2] > 5) return "";

        string B = "00:00";
        if (A[1] > 5) {
            A[2] > 1 ? (B[0] = A[3] + 48, B[3] = A[2] + 48) : (B[0] = A[2] + 48, B[3] = A[3] + 48);
            B[1] = A[0] + 48;
            B[4] = A[1] + 48;
        } else {
            B[0] = getLimitMax(A, 2);
            B[1] = getLimitMax(A, (B[0] == '2' ? 3 : 9));
            B[3] = getLimitMax(A, 5);
            B[4] = getLimitMax(A, 9);
        }
        return B;
    }

private:
    int getLimitMax(vector<int> &A, int limit) {
        for (int i = 0; i < 4; ++i)
            if (A[i] <= limit) {
                int d = A[i];
                A[i] = 10;
                return d + 48;
            }
    }
};
