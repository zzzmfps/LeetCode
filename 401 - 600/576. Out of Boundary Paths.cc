// 8 ms, 74.33%; 9.2 MB, 50.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    using Vec2 = vector<vector<int>>;
    using Vec3 = vector<Vec2>;
    static constexpr long long MODULE = 1000000007L;
    static constexpr int INF = 0x3fffffff;

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        Vec3 cache = Vec3(m, Vec2(n, vector<int>(1 + maxMove, INF)));
        return this->helper(m, n, maxMove, startRow, startColumn, cache);
    }

    int helper(int m, int n, int maxMove, int startRow, int startColumn, Vec3 &cache) {
        if (0 == maxMove) return 0;
        if (INF != cache[startRow][startColumn][maxMove]) return cache[startRow][startColumn][maxMove];

        long long lCount = 0L;
        lCount += (0 == startRow ? 1 : this->helper(m, n, maxMove - 1, startRow - 1, startColumn, cache));
        lCount += (0 == startColumn ? 1 : this->helper(m, n, maxMove - 1, startRow, startColumn - 1, cache));
        lCount += (1 == m - startRow ? 1 : this->helper(m, n, maxMove - 1, startRow + 1, startColumn, cache));
        lCount += (1 == n - startColumn ? 1 : this->helper(m, n, maxMove - 1, startRow, startColumn + 1, cache));
        int iCount = static_cast<int>(lCount % MODULE);
        cache[startRow][startColumn][maxMove] = iCount;
        return iCount;
    }
};
