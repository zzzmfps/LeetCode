// 20ms, 83.86%; 21.5MB, 91.67%
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> st;
        st.push(root);
        bool flag = true; // cursor has NOT reached the left-bottom of the subtree
        while (k) {
            auto tmp = st.top();
            if (flag && tmp->left) {
                st.push(tmp->left);
            } else {
                if (k == 1) break;
                --k, st.pop(), flag = false;
                if (tmp->right) st.push(tmp->right), flag = true;
            }
        }
        return st.top()->val;
    }
};
