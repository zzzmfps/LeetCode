// 7ms, 8.10%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int size = nums.size();
        int end = size - 1;
        for (int i = end; i >= 0; --i)
            if (val == nums[i]) {
                if (end != i) nums[i] = nums[end];
                --end;
            }
        nums.resize(end + 1);
        return end + 1;
    }
};
