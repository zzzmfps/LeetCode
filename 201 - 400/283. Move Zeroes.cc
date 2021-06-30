// 17ms, 32.85%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int ins_index = 0, end = nums.size();
        while (nums[ins_index] != 0) ++ins_index; // when vector nums[ins_index] out of range, it returns 0
        int trav = ins_index + 1;                 // vector<int> v{1, 1}; --> v[2] returns 0
        while (trav < end) {
            if (nums[trav] != 0) swap(nums[trav], nums[ins_index++]);
            ++trav;
        }
    }
};
