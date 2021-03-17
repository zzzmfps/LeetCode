// 60 ms, 71.22%; 16.8 MB, 40.93%
#include <bits/stdc++.h>
using namespace std;

struct Elem {
    int val;
    size_t list, index;
    Elem(int v = 0, size_t l = -1, size_t i = -1) : val(v), list(l), index(i) {}
    friend bool operator>(const Elem &x, const Elem &y) {
        return x.val > y.val;
    }
};
using Pair = pair<int, size_t>;

class Solution {
public:
    vector<int> smallestRange(const vector<vector<int>> &nums) const {
        size_t k = nums.size(), n = 0;
        for_each_n(nums.begin(), k, [&](const vector<int> &v) { n += v.size(); });

        priority_queue<Elem, vector<Elem>, greater<Elem>> pq;
        for (size_t i = 0; i < k; ++i) pq.emplace(nums[i][0], i, 0);

        vector<Pair> merged(n);
        for (auto &e : merged) {
            auto &&t = pq.top();
            e.first = t.val, e.second = t.list;
            if (t.index + 1 < nums[t.list].size()) pq.emplace(nums[t.list][t.index + 1], t.list, t.index + 1);
            pq.pop();
        }

        size_t i = 0, j = 0; // index of merged, j is excluded
        vector<int> counts(k);
        for (size_t uncovered = k; uncovered; ++j) {
            if (0 == counts[merged[j].second]) --uncovered;
            ++counts[merged[j].second];
        }
        while (counts[merged[i].second] > 1) --counts[merged[i++].second];

        vector<int> res = {merged[i].first, merged[j - 1].first};
        for (; j < n; ++j) {
            while (j < n) {
                ++counts[merged[j].second];
                if (merged[i].second == merged[j].second || j + 1 == n) break;
                ++j;
            }
            while (counts[merged[i].second] > 1) --counts[merged[i++].second];
            if (merged[j].first - merged[i].first < res[1] - res[0]) res = {merged[i].first, merged[j].first};
        }

        return res;
    }
};
