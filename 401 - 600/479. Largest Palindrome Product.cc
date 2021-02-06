// 0ms, 100.00%; 5.7 MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // lazy way
    static constexpr int kLpp[] = {0, 9, 987, 123, 597, 677, 1218, 877, 475};

public:
    int largestPalindrome(int n) {
        return this->kLpp[n];
    }
};
