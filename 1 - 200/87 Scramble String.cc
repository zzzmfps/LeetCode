// 4ms, 100.0%; 9.4MB, 85.71%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isScramble(const string &s1, const string &s2) {
        if (s1 == s2) return true;
        int tmp[26]{}, size = s1.size();
        for (int i = 0; i < size; ++i) {
            ++tmp[s1[i] - 97];
            --tmp[s2[i] - 97];
        }
        for (int i = 0; i < 26; ++i)
            if (tmp[i] != 0) return false;
        for (int i = 1; i < size; ++i) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) return true;
            if (isScramble(s1.substr(0, i), s2.substr(size - i)) && isScramble(s1.substr(i), s2.substr(0, size - i)))
                return true;
        }
        return false;
    }
};
