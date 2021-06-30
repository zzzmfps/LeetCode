// 24ms, 94.85%; 14.5MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(const string &s) {
        int slen = s.size();
        stack<int> st;
        vector<int> deleted;
        deleted.reserve(slen);
        for (int i = 0; i < slen; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    deleted.push_back(i);
                }
            }
        }
        while (!st.empty()) {
            deleted.push_back(st.top());
            st.pop();
        }
        deleted.shrink_to_fit();
        if (deleted.empty()) return s;

        sort(deleted.begin(), deleted.end());
        deleted.push_back(slen);
        int i = 0;
        string res = "";
        for (auto j : deleted) {
            res += s.substr(i, j - i);
            i = j + 1;
        }
        return res;
    }
};
