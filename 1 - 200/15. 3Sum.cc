// 101ms, 96.10%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        if (nums.empty() || nums.size() < 3) return vector<vector<int>>();
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        if (nums.back() < 0) return vector<vector<int>>();

        for (int i = 0; i < nums.size() - 2; ++i) {
            int target = -nums[i];
            if (target < 0) break;
            int front = i + 1;
            int back = nums.size() - 1;

            while (front < back) {
                int sum = nums[front] + nums[back];
                if (sum < target)
                    ++front;
                else if (sum > target)
                    --back;
                else {
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[front];
                    triplet[2] = nums[back];
                    res.push_back(triplet);
                    while (front < back && nums[front] == triplet[1]) ++front;
                    while (front < back && nums[back] == triplet[2]) --back;
                }
            }
            while (i < nums.size() - 3 && nums[i + 1] == nums[i]) ++i;
        }
        return res;
    }
};
