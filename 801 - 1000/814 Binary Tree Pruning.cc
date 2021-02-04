// 4ms, 100.00%; 9.9MB, 67.71%
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
    TreeNode *pruneTree(TreeNode *root)
    {
        if (!root) return nullptr;
        prune(root);
        return (root->val == 0 && root->left == root->right ? nullptr : root);
    }

private:
    void prune(TreeNode *root)
    {
        if (root->left) {
            if (check(root->left)) {
                root->left = nullptr;
            } else {
                prune(root->left);
            }
        }
        if (root->right) {
            if (check(root->right)) {
                root->right = nullptr;
            } else {
                prune(root->right);
            }
        }
    }

    bool check(TreeNode *root)
    {
        bool flag = (root->val == 0);
        if (root->left) flag &= check(root->left);
        if (root->right) flag &= check(root->right);
        return flag;
    }
};
