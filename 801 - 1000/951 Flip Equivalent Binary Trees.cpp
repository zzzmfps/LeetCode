// 4ms, 100.00%; 11.9MB, 98.77%
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == root2) return true;
        if (!root1 || !root2 || root1->val != root2->val) return false;

        stack<TreeNode *> st1, st2;
        st1.push(root1), st2.push(root2);
        while (!st1.empty() && !st2.empty()) {
            auto node1 = st1.top(), node2 = st2.top();
            st1.pop(), st2.pop();
            int x1 = (node1->left) ? node1->left->val : 0, x2 = (node1->right) ? node1->right->val : 0;
            int y1 = (node2->left) ? node2->left->val : 0, y2 = (node2->right) ? node2->right->val : 0;
            if (x1 == y1 && x2 == y2) {
                if (node1->left) {
                    st1.push(node1->left);
                    st2.push(node2->left);
                }
                if (node1->right) {
                    st1.push(node1->right);
                    st2.push(node2->right);
                }
            } else if (x1 == y2 && x2 == y1) {
                if (node1->left) {
                    st1.push(node1->left);
                    st2.push(node2->right);
                }
                if (node1->right) {
                    st1.push(node1->right);
                    st2.push(node2->left);
                }
            } else {
                return false;
            }
        }
        return st1.empty() && st2.empty();
    }
};
