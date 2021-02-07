// 8ms, 94.57%
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    TreeNode *buildTree(const vector<int> &inorder, const vector<int> &postorder) {
        if (inorder.empty()) return nullptr;

        TreeNode *root = new TreeNode(postorder.back());
        int i = postorder.size() - 2, j = inorder.size() - 1;
        stack<TreeNode *> st;
        st.push(root);

        while (i >= 0) {
            TreeNode *node = new TreeNode(postorder[i--]);
            TreeNode *tmp = nullptr;
            while (!st.empty() && st.top()->val == inorder[j]) {
                tmp = st.top();
                st.pop();
                --j;
            }
            (tmp ? tmp->left : st.top()->right) = node;
            st.push(node);
        }

        return root;
    }
};
