// 49ms, 100.0%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution {
public:
    bool validPalindrome(string s) {
        if (s == string(s.rbegin(), s.rend())) return true;
        int i = 0, j = s.size() - 1;
        while (i < j)
            if (s[i] == s[j])
                ++i, --j;
            else {
                string remove_i = s;
                remove_i.erase(remove_i.begin() + i);
                s.erase(s.begin() + j);
                return remove_i == string(remove_i.rbegin(), remove_i.rend()) || s == string(s.rbegin(), s.rend());
            }
    }
};
