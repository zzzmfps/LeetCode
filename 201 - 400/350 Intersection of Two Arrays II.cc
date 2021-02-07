// 8ms, 70.61%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> um;
        for (auto x : nums1) {
            if (um.find(x) != um.end())
                um[x] += 1;
            else
                um[x] = 1;
        }
        vector<int> res;
        for (auto y : nums2) {
            if (um.find(y) != um.end() && um[y]) {
                res.push_back(y);
                um[y] -= 1;
            }
        }
        return res;
    }
};
