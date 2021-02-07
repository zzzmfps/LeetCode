// 12ms, 96.67%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string shortestCompletingWord(const string &licensePlate, const vector<string> &words) {
        int count = 0;
        map<char, int> lp;
        for (const auto c : licensePlate)
            if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') lp[tolower(c)] += 1, count += 1;

        int last = 16;
        string ret = "";
        for (const auto &word : words) {
            if (word.size() >= last) continue;
            if (check(lp, word) == count) ret = word, last = word.size();
        }
        return ret;
    }

private:
    int check(map<char, int> lp, const string &word) {
        int tmp = 0;
        for (const auto w : word)
            if (lp.find(w) != lp.end() && lp[w] > 0) tmp += 1, lp[w] -= 1;
        return tmp;
    }
};
