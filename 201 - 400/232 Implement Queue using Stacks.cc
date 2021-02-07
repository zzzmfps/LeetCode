// 4ms, 0.00%
#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> st;

public:
    MyQueue() {}

    void push(int x) {
        pushHelper(x);
    }

    void pushHelper(int x) {
        if (st.empty()) {
            st.push(x);
            return;
        }
        int tmp = st.top();
        st.pop();
        pushHelper(x);
        st.push(tmp);
    }

    int pop() {
        int tmp = st.top();
        st.pop();
        return tmp;
    }

    int peek() {
        return st.top();
    }

    bool empty() {
        return st.empty();
    }
};
