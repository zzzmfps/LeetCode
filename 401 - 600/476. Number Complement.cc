// 4ms, 99.89%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution {
public:
    int findComplement(int num) {
        int ex = 0;
        while (++ex < num) ex <<= 1;
        return ex - num;
    }
};
