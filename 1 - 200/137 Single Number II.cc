// 4ms, 100.0%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int singleNumber(const vector<int> &nums) {
        int ones = 0, twos = 0;
        for (const auto n : nums) {
            ones ^= ~twos & n;
            twos ^= ~ones & n;
        }
        return ones;
    }
};
