// 8ms, 99.26%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<int> majorityElement(const vector<int> &nums) {
        vector<int> res;
        if (!nums.empty()) {
            int num[2] = {0, 1}, count[2] = {0, 0}, limit = nums.size() / 3;
            for (const auto n : nums)
                if (n == num[0]) {
                    ++count[0];
                } else if (n == num[1]) {
                    ++count[1];
                } else if (count[0] == 0) {
                    num[0] = n, ++count[0];
                } else if (count[1] == 0) {
                    num[1] = n, ++count[1];
                } else {
                    --count[0], --count[1];
                }

            if (num[0] > num[1]) swap(num[0], num[1]);
            count[0] = count[1] = 0;
            for (const auto n : nums)
                if (n == num[0]) {
                    ++count[0];
                } else if (n == num[1]) {
                    ++count[1];
                }

            if (count[0] > limit) res.push_back(num[0]);
            if (count[1] > limit) res.push_back(num[1]);
        }
        return res;
    }
};
