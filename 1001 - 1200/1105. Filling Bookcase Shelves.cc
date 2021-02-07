// 4 ms, 98.14%; 8.2 MB, 86.98%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minHeightShelves(const vector<vector<int>> &books, int shelf_width) {
        vector<int> dp(books.size());
        for (int i = 0; i < books.size(); ++i) {
            int width = books[i][0], height = books[i][1];
            dp[i] = height + (0 == i ? 0 : dp[i - 1]);
            for (int j = i - 1; j > -1; --j) {
                width += books[j][0];
                if (width > shelf_width) break;
                height = max(height, books[j][1]);
                dp[i] = min(dp[i], height + (0 == j ? 0 : dp[j - 1]));
            }
        }
        return dp.back();
    }
};
