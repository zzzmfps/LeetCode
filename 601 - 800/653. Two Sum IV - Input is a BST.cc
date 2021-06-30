// 36ms, 89.08%; 26.8MB, 24.14%
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

auto x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool findTarget(TreeNode *root, int k) {
        unordered_set<int> targets;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            if (targets.find(node->val) != targets.end()) return true;
            targets.insert(k - node->val);
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }
        return false;
    }
};
