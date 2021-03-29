// 12 ms, 99.64%; 7.8 MB, 86.18%
#include <bits/stdc++.h>
using namespace std;

static constexpr int MAX = 100;
static constexpr int INF = 1000000;

class Solution {
private:
    int costs[MAX][MAX], cache[MAX][MAX];

public:
    int minDistance(vector<int> &houses, size_t k) {
        size_t n = houses.size();
        if (n == k) return 0;

        sort(houses.begin(), houses.end());
        for (size_t i = 0; i < n; ++i)
            for (size_t j = 0; j < n; ++j) this->costs[i][j] = this->dist(houses, i, j);
        memset(this->cache, -1, sizeof(this->cache));

        return this->dp(houses, k, 0);
    }

private:
    int dp(const vector<int> &houses, size_t k, size_t i) {
        if (0 == k && i == houses.size()) return 0;
        if (0 == k || i == houses.size()) return INF;
        if (-1 != this->cache[k][i]) return this->cache[k][i];
        int ret = INF;
        for (int j = i; j < houses.size(); ++j) ret = min(ret, costs[i][j] + this->dp(houses, k - 1, j + 1));
        return this->cache[k][i] = ret;
    }

    int dist(const vector<int> &houses, size_t i, size_t j) {
        int ret = 0;
        while (i < j) ret += houses[j--] - houses[i++];
        return ret;
    }
};
