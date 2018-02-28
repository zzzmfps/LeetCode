// 26ms, 28.44%
class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int res = nums.size(), i = 0;
        for (auto n : nums) {
            res ^= n;    // n: 0 ~ (j missed) ~ size + 1, 0 <= j <= size + 1
            res ^= i;    // i, res: 0 ~ size + 1
            ++i;
        }
        return res;
    }
};
