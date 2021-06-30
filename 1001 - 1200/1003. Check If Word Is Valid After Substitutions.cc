// 8ms, 100.0%; 10.5MB, 100.0%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isValid(const string &S) {
        stack<int> st;
        int index;
        for (const auto c : S) {
            index = (c == 'a') ? 1 : (c == 'b') ? 2 : 3;
            if (index == 1) {
                st.push(1);
            } else if (!st.empty() && index == 1 + st.top()) {
                if (index == 3) {
                    st.pop();
                } else {
                    st.top() = index;
                }
            } else {
                return false;
            }
        }
        return st.empty();
    }
};
