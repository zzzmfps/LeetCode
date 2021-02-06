// 20 ms, 82.73%; 17 MB, 98.04%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        int counts[5001]{};
        for (auto &&n : nums) ++counts[n];

        int i1 = 0, j1 = nums.size() - (nums.size() & 1 ? 1 : 2);
        int i2 = 5000, j2 = 1;
        while (j2 < nums.size()) {
            while (0 == counts[i1]) ++i1;
            while (0 == counts[i2]) --i2;
            nums[j1] = i1, j1 -= 2, --counts[i1];
            nums[j2] = i2, j2 += 2, --counts[i2];
        }
        if (0 == j1) {
            while (0 == counts[i1]) ++i1;
            nums[j1] = i1;
        }
    }
};
