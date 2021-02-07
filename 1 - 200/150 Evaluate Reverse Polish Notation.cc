// 7ms, 100.0%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution {
private:
    string valid[4] = {"+", "-", "*", "/"};
    stack<int> tmp_stack;

public:
    int evalRPN(const vector<string> &tokens) {
        int res = stoi(tokens[0]);
        int index = -1, size = tokens.size();
        while (++index < size) {
            string ti = tokens[index];
            if (ti == valid[0] || ti == valid[1] || ti == valid[2] || ti == valid[3]) {
                int num2 = tmp_stack.top();
                tmp_stack.pop();
                int num1 = tmp_stack.top();
                tmp_stack.pop();
                res = ti == valid[0]   ? num1 + num2
                      : ti == valid[1] ? num1 - num2
                      : ti == valid[2] ? num1 * num2
                                       : num1 / num2;
                tmp_stack.push(res);
            } else
                tmp_stack.push(stoi(ti));
        }
        return res;
    }
};
