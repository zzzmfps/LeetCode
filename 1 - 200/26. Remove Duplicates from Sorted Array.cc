// 29ms, 37.41%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int size = nums.size();
        if (size <= 1) return size;

        int elem = nums[0];
        int count = 0;
        for (int i = 1; i < size; ++i)
            if (nums[i] == elem)
                ++count;
            else {
                elem = nums[i];
                if (count != 0) nums[i - count] = nums[i];
            }

        int length = size - count;
        nums.resize(length);
        return length;
    }
};
