// 8ms, 98.64%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int minSubArrayLen(int s, const vector<int> &nums) {
        int size = nums.size(), ret = 0x7FFFFFFF;
        int end = 0, sum = 0;
        for (int start = 0; start < size; ++start) {
            while (sum < s) {
                if (end == size) break;
                sum += nums[end++];
            }
            if (sum >= s) {
                ret = min(ret, end - start);
                sum -= nums[start];
            } else {
                break;
            }
        }
        return (ret == 0x7FFFFFFF) ? 0 : ret;
    }
};
