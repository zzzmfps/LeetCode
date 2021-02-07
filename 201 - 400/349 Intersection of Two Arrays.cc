// 7ms, 96.15%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> n1(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto x : nums2) {
            if (n1.find(x) != n1.end()) {
                res.push_back(x);
                n1.erase(x);
            }
        }
        return res;
    }
};
