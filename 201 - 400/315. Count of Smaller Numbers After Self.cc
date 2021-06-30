// 32ms, 82.83%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution {
private:
    vector<int> smaller;

public:
    vector<int> countSmaller(const vector<int> &nums) {
        int size = nums.size();
        smaller = vector<int>(size, 0);
        vector<pair<int, int>> enums(size);
        for (int i = 0; i < size; ++i) enums[i] = make_pair(i, nums[i]);
        helper(move(enums));
        return smaller;
    }

private:
    vector<pair<int, int>> helper(vector<pair<int, int>> &&enums) {
        int size = enums.size();
        int half = size / 2;
        if (half) {
            auto left = helper(vector<pair<int, int>>(enums.begin(), enums.begin() + half));
            auto right = helper(vector<pair<int, int>>(enums.begin() + half, enums.end()));
            for (int i = size - 1; i >= 0; --i)
                if (right.empty() || !left.empty() && left.back().second > right.back().second) {
                    smaller[left.back().first] += right.size();
                    enums[i] = left.back();
                    left.pop_back();
                } else {
                    enums[i] = right.back();
                    right.pop_back();
                }
        }
        return enums;
    }
};
