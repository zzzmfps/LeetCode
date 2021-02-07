// 44ms, 100.00%; 11.8MB, 11.11%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int res = 0;
        int i = 1, size = heaters.size();
        heaters.push_back(heaters.back());
        for (auto pos : houses) {
            while (i < size && heaters[i] <= pos) ++i;
            res = max(res, min(abs(heaters[i - 1] - pos), abs(heaters[i] - pos)));
        }
        return res;
    }
};
