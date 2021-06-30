// 4ms, 100.0%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isAlienSorted(const vector<string> &words, const string &order) {
        unordered_map<char, int> dist;
        dist.reserve(52);
        for (int i = 0, size = order.size(); i < size; ++i) dist[order[i]] = i;

        for (int i = 0, size = words.size() - 1; i < size; ++i) {
            auto &x = words[i], &y = words[i + 1];
            int len = min(x.size(), y.size()), j;
            for (j = 0; j < len; ++j) {
                if (x[j] == y[j]) continue;
                if (dist[x[j]] < dist[y[j]]) break;
                return false;
            }
            if (j == len && x.size() > y.size()) return false;
        }
        return true;
    }
};
