// 0ms, 100.0%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool checkPerfectNumber(int num) {
        unordered_set<int> perfect({6, 28, 496, 8128, 33550336});
        return perfect.find(num) != perfect.end();
    }
};
