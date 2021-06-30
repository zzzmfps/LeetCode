// 2ms, 14.37%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while (n) {
            ans += char((n - 1) % 26 + 'A');
            n = (n - 1) / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
