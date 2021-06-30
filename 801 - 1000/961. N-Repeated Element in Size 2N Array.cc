// 16ms, 98.17%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int repeatedNTimes(const vector<int> &A) {
        unordered_set<int> tmp;
        for (const auto a : A) {
            if (tmp.find(a) != tmp.end()) return a;
            tmp.insert(a);
        }
        return 0; // nop
    }
};
