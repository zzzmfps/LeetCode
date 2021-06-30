// 31ms, 99.25%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
private:
    unordered_map<int, vector<int>> record;
    vector<int> maxNums;

public:
    int findShortestSubArray(const vector<int> &nums) {
        int size = nums.size(), num = 0;
        for (int i = 0; i < size; ++i) {
            record[nums[i]].push_back(i);
            if (num < record[nums[i]].size()) {
                num = record[nums[i]].size();
                maxNums.clear();
            }
            if (num == record[nums[i]].size()) maxNums.push_back(nums[i]);
        }

        num = nums.size();
        for (const auto n : maxNums) num = min(num, record[n].back() - record[n][0] + 1);
        return num;
    }
};
