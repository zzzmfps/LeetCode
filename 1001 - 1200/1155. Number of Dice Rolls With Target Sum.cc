// 24 ms, 58.89%; 8.4 MB, 32.29%
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    static constexpr long long MODULE = 1000000007LL;

public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> cache(1 + d, vector<int>(1 + target, -1));
        return this->helper(d, f, target, cache);
    }

private:
    int helper(int d, int f, int target, vector<vector<int>> &cache) {
        if (0 == d) return 0 == target;
        if (-1 != cache[d][target]) return cache[d][target];
        long long count = 0LL;
        for (size_t i = min(f, target - d + 1); i > 0; --i) {
            count += this->helper(d - 1, f, target - i, cache);
            count %= MODULE;
        }
        cache[d][target] = static_cast<int>(count);
        return cache[d][target];
    }
};
