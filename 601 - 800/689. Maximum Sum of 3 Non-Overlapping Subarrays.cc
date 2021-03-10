// 24 ms, 90.81%; 19.9 MB, 70.63%
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int k;
    vector<int> acc;

public:
    vector<int> maxSumOfThreeSubarrays(const vector<int> &nums, int k) {
        int size = nums.size();

        this->acc = nums, this->k = k;
        for (int i = 1; i < size; ++i) this->acc[i] += this->acc[i - 1];

        vector<vector<int>> dp(3);
        auto check = [&](int turn, int i, int &v1, int v2) {
            if (v2 > v1) {
                dp[turn][i] = i, v1 = v2;
            } else {
                dp[turn][i] = dp[turn][i - 1];
            }
        };

        dp[0] = vector<int>(size - 3 * k + 1, 0);
        for (int i = 1, v1 = this->getSum(0); i < dp[0].size(); ++i) {
            int v2 = this->getSum(i);
            check(0, i, v1, v2);
        }
        dp[1] = vector<int>(size - 2 * k + 1, k);
        for (int i = k + 1, v1 = this->getSum(0, k); i < dp[1].size(); ++i) {
            int v2 = this->getSum(dp[0][i - k], i);
            check(1, i, v1, v2);
        }
        dp[2] = vector<int>(size - k + 1, 2 * k);
        for (int i = 2 * k + 1, v1 = this->getSum(0, k, 2 * k); i < dp[2].size(); ++i) {
            int v2 = this->getSum(dp[0][dp[1][i - k] - k], dp[1][i - k], i);
            check(2, i, v1, v2);
        }

        vector<int> res = {size};
        for (int i = 2; i > -1; --i) res.push_back(dp[i][res.back() - k]);
        return vector<int>(res.rbegin(), prev(res.rend()));
    }

private:
    template <typename T, typename... Ts>
    int getSum(T id, Ts... args) {
        int ret = this->acc[id + this->k - 1] - (0 == id ? 0 : this->acc[id - 1]);
        if constexpr (sizeof...(args) > 0) ret += this->getSum(args...);
        return ret;
    }
};
