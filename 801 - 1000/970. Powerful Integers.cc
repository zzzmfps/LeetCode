// 4ms, 68.86%; 8.6MB, 31.85%
#include <bits/stdc++.h>
using namespace std;

auto _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> xExp = {1}, yExp = {1};
        if (x > 1)
            for (int i = x; i < bound; i *= x) xExp.push_back(i);
        if (y > 1)
            for (int i = y; i < bound; i *= y) yExp.push_back(i);
        vector<int> res;
        res.reserve(xExp.size() * yExp.size());
        for (auto x : xExp) {
            for (auto y : yExp) {
                if (x + y > bound) break;
                res.push_back(x + y);
            }
        }
        res.shrink_to_fit();
        sort(res.begin(), res.end());
        res.resize(distance(res.begin(), unique(res.begin(), res.end())));
        return res;
    }
};
