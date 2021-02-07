// 13ms, 99.55%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution {
private:
    map<string, int> visits;
    vector<string> res;

public:
    vector<string> subdomainVisits(const vector<string> &cpdomains) {
        for (auto domain : cpdomains) {
            int tmp = domain.find(' ');
            int count = stoi(domain.substr(0, tmp));
            do {
                domain = domain.substr(tmp + 1);
                visits[domain] += count;
            } while ((tmp = domain.find('.')) != string::npos);
        }
        for (const auto &v : visits) res.push_back(to_string(v.second) + ' ' + v.first);
        return res;
    }
};
