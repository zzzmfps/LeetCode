// 9ms, 21.13%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
        int lenn = n.size();
        auto mirror = [lenn, &n](long mid, int d) {
            string prefix = to_string(mid + d);
            return stol(prefix + string(prefix.rbegin() + (lenn % 2), prefix.rend()));
        };

        long mid = stol(n.substr(0, (lenn + 1) / 2));
        set<long> candidates = {mirror(mid, -1), mirror(mid, 0), mirror(mid, 1), long(pow(10, lenn - 1)) - 1,
                                long(pow(10, lenn)) + 1};

        long num = stol(n);
        candidates.erase(num);
        return to_string(*min_element(candidates.begin(), candidates.end(),
                                      [num](long a, long b) { return abs(num - a) < abs(num - b); }));
    }
};
