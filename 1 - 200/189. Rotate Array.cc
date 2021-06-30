// 21ms, 41.46%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        if (nums.empty()) return;
        int size = nums.size();
        if (!(k %= size)) return;

        int *tmp = new int[k];
        for (int i = 0; i < k; ++i) tmp[i] = nums[size - k + i];
        for (int i = 0; i < size - k; ++i) nums[size - 1 - i] = nums[size - 1 - k - i];
        for (int i = 0; i < k; ++i) nums[i] = tmp[i];
        delete[] tmp;
    }
};
