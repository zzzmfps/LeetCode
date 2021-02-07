// 32ms, 98.84%; 11.7MB, 100.0%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int findMaxConsecutiveOnes(const vector<int> &nums) {
        int bits = 0, tmp = 0;
        for (const auto n : nums)
            if (n == 0) {
                bits = max(bits, tmp);
                tmp = 0;
            } else {
                tmp += 1;
            }
        return max(bits, tmp);
    }
};
