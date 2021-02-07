// 8ms, 100.0%; 10.1MB, 98.80%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxDistToClosest(const vector<int> &seats) {
        auto it1 = find(seats.begin(), seats.end(), 1);
        auto it2 = find(seats.rbegin(), seats.rend(), 1);

        int last = distance(seats.begin(), it1), end = distance(seats.rbegin(), it2);
        int res = max(last, end), limit = seats.size() - end;

        for (int i = last + 1; i < limit; ++i) {
            if (seats[i] == 0) continue;
            res = max(res, (i - last) / 2);
            last = i;
        }
        return res;
    }
};
