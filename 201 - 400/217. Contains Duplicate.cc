// 37ms, 44.14%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        if (nums.empty()) return false;
        unordered_set<int> tmp;
        int i = 0;
        while (tmp.find(nums[i]) == tmp.end()) {
            tmp.insert(nums[i++]);
            if (i == nums.size()) return false;
        }
        return true;
    }
};
