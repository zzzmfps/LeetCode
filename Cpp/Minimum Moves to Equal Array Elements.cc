// 51ms, 90.20%
class Solution {
public:
    int minMoves(vector<int> &nums) {
        int min = nums[0], res = 0;
        for (auto n : nums) {
            if (n < min) min = n;
            res += (n - nums[0]);
        }
        return res + (nums[0] - min) * nums.size();
    }
};
