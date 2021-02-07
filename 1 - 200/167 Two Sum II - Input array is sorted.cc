// 7ms, 18.16%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int beg = 0, end = numbers.size() - 1;
        while (true) {
            if (numbers[beg] + numbers[end] < target)
                ++beg;
            else if (numbers[beg] + numbers[end] > target)
                --end;
            else
                return vector<int>{beg + 1, end + 1};
        }
    }
};
