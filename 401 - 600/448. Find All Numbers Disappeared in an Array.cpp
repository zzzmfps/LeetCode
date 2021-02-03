// 48 ms, 94.85%; 33.7 MB, 78.25%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        for (int i = 0; i < nums.size();) {
            if (nums[i] == i + 1 || nums[i] == nums[nums[i] - 1]) {
                ++i;
            } else {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] != i + 1) res.push_back(i + 1);
        return res;
    }
};
