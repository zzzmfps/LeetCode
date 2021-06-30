// 4ms, 100.0%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution {
public:
    bool makesquare(vector<int> &nums) {
        if (nums.size() < 4) return false;
        int perimeter = accumulate(nums.begin(), nums.end(), 0);
        int target = perimeter / 4;
        if (target * 4 != perimeter) return false;
        sort(nums.rbegin(), nums.rend());
        int edges[4] = {};
        return divide(edges, nums, 0, target);
    }

private:
    bool divide(int *edges, const vector<int> &nums, int index, int target) {
        if (index == nums.size()) return true;
        for (int i = 0; i < 4; ++i) {
            if (edges[i] + nums[index] > target ||
                any_of(edges, edges + i, [edges, i](int x) { return x == edges[i]; }))
                continue;
            edges[i] += nums[index];
            if (divide(edges, nums, index + 1, target)) return true;
            edges[i] -= nums[index];
        }
        return false;
    }
};
