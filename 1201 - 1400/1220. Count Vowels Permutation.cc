// 28 ms, 54.55%; 21.9 MB, 30.25%
#include <bits/stdc++.h>
using namespace std;

using LL = long long;
static constexpr LL MODULE = 1000000007LL;
static const vector<vector<int>> VOWELS = {{1}, {0, 2}, {0, 1, 3, 4}, {2, 4}, {0}};

class Solution {
public:
    int countVowelPermutation(int n) {
        LL *cache[5];
        for (size_t i = 0; i < VOWELS.size(); ++i) cache[i] = new LL[1 + n]{};

        auto helper = [&](auto &&self, int n_, int c_) -> LL {
            if (1 == n_) return 1LL;
            auto &record = cache[c_][n_];
            if (record) return record;
            for (auto &&c_2 : VOWELS.at(c_)) record += self(self, n_ - 1, c_2);
            return (record %= MODULE);
        };
        LL res = 0LL;
        for (size_t i = 0; i < VOWELS.size(); ++i) res += helper(helper, n, i);

        for (size_t i = 0; i < VOWELS.size(); ++i) delete[] cache[i];
        return static_cast<int>(res % MODULE);
    }
};
