// 244 ms, 98.20%; 74.5 MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canDistribute(const vector<int> &nums, vector<int> quantity) const {
        vector<int> counts = getCounts(nums);
        sort(quantity.rbegin(), quantity.rend());
        while (!counts.empty() && !quantity.empty()) {
            if (counts.back() < quantity.back()) {
                counts.pop_back();
            } else if (counts.back() == quantity.back() || 1 == quantity.size()) {
                counts.pop_back(), quantity.pop_back();
            } else {
                break;
            }
        }
        if (quantity.empty()) return true;
        if (counts.empty()) return false;
        return check(counts, quantity, 0);
    }

private:
    vector<int> getCounts(const vector<int> &nums) const {
        int hash[1001] = {};
        for (auto &&n : nums) ++hash[n];
        vector<int> counts;
        for (int i = 1; i < 1001; ++i)
            if (0 != hash[i]) counts.push_back(hash[i]);
        sort(counts.rbegin(), counts.rend());
        return counts;
    }

    bool check(vector<int> &counts, const vector<int> &quantity, int i) const {
        int value = quantity[i];
        for (auto &&count : counts) {
            if (count < value) continue;
            if (i == quantity.size() - 1) return true;
            count -= value;
            if (check(counts, quantity, i + 1)) return true;
            count += value;
        }
        return false;
    }
};
