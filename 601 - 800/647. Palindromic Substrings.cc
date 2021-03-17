// 8 ms, 72.07%; 6.3 MB, 86.01%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(const string &s) {
        int size = static_cast<int>(s.size());
        if (size < 2) return size;
        int start = 1;

        bool *dp[2] = {new bool[size], new bool[size]}; // odd, even
        fill_n(dp[0], size, true);
        for (int i = start; i < size; ++i) dp[1][i] = (s[i] == s[i - 1]);

        int count = size + this->count(dp[1], start, size);
        while (true) {
            for (int i = 0; i < 2; ++i) {
                if (++start == size) goto breakAll;
                for (int j = size - 1; j >= start; --j) dp[i][j] = dp[i][j - 1] && (s[j] == s[j - start]);
                count += this->count(dp[i], start, size);
            }
        }

    breakAll:
        delete[] dp[0], delete[] dp[1];
        return count;
    }

private:
    int count(bool *dp, int start, int end) {
        return count_if(dp + start, dp + end, [](bool b) { return b; });
    }
};
