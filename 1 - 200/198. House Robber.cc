// 2ms, 38.10%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.empty()) return 0;
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); ++i)
            if (i % 2 == 0)
                a = max(a + nums[i], b);
            else
                b = max(a, b + nums[i]);
        return max(a, b);
    }
};
