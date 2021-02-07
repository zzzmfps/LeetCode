// 16ms, 99.02%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string shiftingLetters(const string &S, vector<int> &shifts) {
        int size = shifts.size();
        shifts[size - 1] %= 26;
        for (int i = size - 2; i >= 0; --i) shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
        string res = "";
        for (int i = 0; i < size; ++i) {
            int y = S[i] + shifts[i];
            res += char(y > 122 ? y - 26 : y);
        }
        return res;
    }
};
