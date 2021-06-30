// 8ms, 100.0%; 10.8MB, 20.35%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        heights.push_back(0);
        stack<int> st;
        int res = 0, i = 0, size = heights.size();
        while (i < size) {
            if (st.empty() || heights[i] > heights[st.top()]) {
                st.push(i++);
            } else {
                int ptr = st.top();
                st.pop();
                res = max(res, heights[ptr] * (st.empty() ? i : i - st.top() - 1));
            }
        }
        return res;
    }
};
