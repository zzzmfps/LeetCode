// 2ms, 18.20%
#include <bits/stdc++.h>
using namespace std;

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int beg = 1;
        while (beg < n) {
            int mid = beg + (n - beg) / 2; // not "(beg + n) / 2" to avoid overflow
            if (isBadVersion(mid))
                n = mid;
            else
                beg = mid + 1;
        }
        return beg;
    }
};
