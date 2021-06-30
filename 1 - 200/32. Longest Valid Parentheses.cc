// 11ms, 29.50%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() <= 1) return 0;
        int curMax = 0;
        vector<int> longest(s.size(), 0);
        for (int i = 1; i < s.size(); ++i)
            if (s[i] == ')') {
                if (s[i - 1] == '(')
                    longest[i] = i >= 2 ? longest[i - 2] + 2 : 2;
                else if (i - longest[i - 1] - 1 >= 0 && s[i - longest[i - 1] - 1] == '(')
                    longest[i] =
                        longest[i - 1] + 2 + ((i - longest[i - 1] - 2 >= 0) ? longest[i - longest[i - 1] - 2] : 0);
                curMax = longest[i] > curMax ? longest[i] : curMax;
            }
        return curMax;
    }
};
