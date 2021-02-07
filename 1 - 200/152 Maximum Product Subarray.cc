// 5ms, 98.12%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution {
private:
    vector<vector<int>> sep;

public:
    int maxProduct(const vector<int> &nums) {
        separate(nums);
        int max_p = sep.size() == 1 ? nums[0] : 0;
        for (const auto s : sep) {
            int whole = 1, left = 1, right = 1, neg_cnt = 0;
            for (const auto n : s) {
                whole *= n;
                neg_cnt += n < 0 ? 1 : 0;
            }
            if (neg_cnt % 2 && s.size() > 1) {
                int i = 0, j = s.size() - 1;
                while (i < j) {
                    left *= s[i];
                    if (s[i++] < 0) break;
                }
                while (-1 < j) {
                    right *= s[j];
                    if (s[j--] < 0) break;
                }
            }
            max_p = max({max_p, whole, whole / left, whole / right});
        }
        return max_p;
    }

private:
    void separate(const vector<int> &nums) {
        vector<int> tmp;
        for (auto n : nums)
            if (n != 0)
                tmp.push_back(n);
            else if (!tmp.empty()) {
                sep.push_back(tmp);
                tmp.clear();
            }
        if (!tmp.empty()) sep.push_back(tmp);
    }
};
