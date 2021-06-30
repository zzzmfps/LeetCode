// 16ms, 100.0%; 9.3MB, 100.0%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
private:
    int f[100][100];

public:
    int strangePrinter(string &s) {
        memset(f, 0, sizeof(f));
        s.erase(unique(s.begin(), s.end()), s.end());
        return dp(s, 0, s.size() - 1);
    }

private:
    int dp(const string &s, int l, int r) {
        if (l > r) return 0;
        if (f[l][r]) return f[l][r];
        f[l][r] = 1 + dp(s, l, r - 1);
        for (int i = l; i < r; ++i)
            if (s[i] == s[r]) f[l][r] = min(f[l][r], dp(s, l, i) + dp(s, i + 1, r - 1));
        return f[l][r];
    }
};
