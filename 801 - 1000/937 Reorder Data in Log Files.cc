// 12ms, 100.0%; 14MB, 65.28%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<string> reorderLogFiles(vector<string> &logs) {
        int idx = divide(logs);
        sort(logs.begin(), logs.begin() + idx, sortRule);
        return logs;
    }

private:
    int divide(vector<string> &logs) {
        // move all digit-logs to the right and keep their order unchanged.
        // return the next index of the last letter-log (>= 0).
        auto pred = [](const string &x) { return x.back() >= 'a'; };
        int l = logs.size() - 1, r = l;
        while (l >= 0) {
            if (pred(logs[l])) {
                --l;
            } else if (l == r) {
                l = r = l - 1;
            } else {
                swap(logs[l--], logs[r--]);
            }
        }
        return r + 1;
    }

    static bool sortRule(const string &x, const string &y) {
        // sort letter-logs.
        auto it1 = x.find(' '), it2 = y.find(' ');
        auto x1 = x.substr(0, it1), x2 = x.substr(it1 + 1);
        auto y1 = y.substr(0, it2), y2 = y.substr(it2 + 1);
        return (x2 < y2 ? true : (x2 > y2 ? false : x1 < y1));
    }
};
