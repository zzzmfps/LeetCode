// 56ms, 93.95%; 56.6MB, 10.53%
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node *root) {
        if (!root) return vector<int>();
        vector<Node *> st = {root};
        vector<int> res;
        while (!st.empty()) {
            Node *tmp = st.back();
            st.pop_back();
            res.push_back(tmp->val);
            st.insert(st.end(), tmp->children.rbegin(), tmp->children.rend());
        }
        return res;
    }
};
