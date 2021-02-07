// 8ms, 99.75%; 8.9MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(const vector<int> &A, int K) { // binary search based
        int size = A.size();
        double l = 0.0, r = 1.0; // all fractions' values are within (0, 1)
        while (true) {
            double m = l + (r - l) / 2;
            int cnt = 0, p = 0, q = 1;
            for (int i = 0, j = 1; i < size; ++i) {
                while (j < size && A[i] > m * A[j]) ++j; // until the first one not greater than m
                cnt += size - j;                         // numbers less than or equal to m
                if (cnt > K) break;                      // prune when obviously not correct
                if (j < size && p * A[j] < q * A[i]) p = A[i], q = A[j];
            }
            if (cnt == K) return vector<int>{p, q};
            (cnt < K ? l : r) = m;
        }
        return vector<int>();
    }
};
