// 144ms, 86.45%; 41.1MB, 92.73%
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int rangeSumBST(TreeNode *root, int L, int R)
    {
        stack<TreeNode *> st;
        st.push(root);
        int _sum = 0;
        while (!st.empty()) { // a bit faster than recursion, but close
            auto tmp = st.top();
            st.pop();
            if (tmp->val >= L && tmp->val <= R) _sum += tmp->val;
            if (tmp->left && tmp->val > L) st.push(tmp->left);
            if (tmp->right && tmp->val < R) st.push(tmp->right);
        }
        return _sum;
    }
};
