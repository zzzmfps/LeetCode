// 4ms, 100.0%; 8.6MB, 100.0%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string reorganizeString(string &S) {
        unordered_map<char, int> count;
        for (const auto c : S) ++count[c];
        string res = "";

        char tmp = ' ';
        while (!count.empty()) {
            auto iter = max_element(count.begin(), count.end(), [tmp](const auto &x, const auto &y) {
                return (x.first == tmp) ? true : (y.first == tmp) ? false : x.second < y.second;
            });
            if (tmp == iter->first) return "";
            tmp = iter->first;
            res += tmp;
            if (iter->second == 1) {
                count.erase(iter);
            } else {
                --iter->second;
            }
        }
        return res;
    }
};
