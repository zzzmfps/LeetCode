// 0ms, 100.00%; 9.1MB, 75.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, const string &B) {
        unordered_map<string, int> m;
        A += " " + B;
        for (int i = 0, j; true; i = j + 1) {
            j = A.find(' ', i);
            m[A.substr(i, j - i)] += 1;
            if (j == string::npos) break;
        }
        vector<string> res;
        for (auto &p : m)
            if (p.second == 1) res.push_back(p.first);
        return res;
    }
};
