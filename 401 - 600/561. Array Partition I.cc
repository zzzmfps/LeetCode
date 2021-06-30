// 40ms, 99.09%; 11.1MB, 92.51%
#include <bits/stdc++.h>
using namespace std;

auto x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int arrayPairSum(vector<int> &nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int res = 0;
        for (int i = 1, size = nums.size(); i < size; i += 2) res += nums[i];
        return res;
    }
};
