#include <bits/stdc++.h>
using namespace std;

// 0, recursion: 4 ms, 62.21%; 6.9 MB, 97.04%
class Solution0 {
public:
    vector<vector<int>> subsets(vector<int> nums) {
        vector<vector<int>> res;
        res.reserve(int(pow(2, nums.size())));
        helper(res, nums, 0);
        return res;
    }

private:
    void helper(vector<vector<int>> &res, vector<int> &nums, int start) {
        if (nums.empty()) {
            res.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            int value = nums[i];
            nums.erase(nums.begin() + i);
            helper(res, nums, i);
            nums.insert(nums.begin() + i, value);
        }
        res.push_back(nums);
    }
};

// 1, bit op: 4 ms, 62.21%; 7.1 MB, 91.03%
class Solution1 {
public:
    vector<vector<int>> subsets(const vector<int> &nums) {
        int counts = int(pow(2, nums.size()));

        vector<vector<int>> res;
        res.reserve(counts);

        for (int i = 0; i < counts; ++i) {
            vector<int> tmp;
            int exp = 1, index = 0;
            while (exp < counts) {
                if (i & exp) tmp.push_back(nums[index]);
                exp <<= 1, ++index;
            }
            res.push_back(tmp);
        }
        return res;
    }
};
