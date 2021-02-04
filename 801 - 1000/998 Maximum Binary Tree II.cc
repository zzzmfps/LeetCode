// 8ms, 43.05%; 11.3MB, 20.00%
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
    TreeNode *insertIntoMaxTree(TreeNode *root, int val)
    {
        if (!root) return new TreeNode(val);
        if (root->val < val) {
            TreeNode *node = new TreeNode(val);
            node->left = root;
            return node;
        }
        return insert(root, root->right, val);
    }

private:
    TreeNode *insert(TreeNode *parent, TreeNode *child, int val)
    {
        if (!child) {
            parent->right = new TreeNode(val);
        } else if (child->val < val) {
            parent->right = new TreeNode(val);
            parent->right->left = child;
        } else {
            insert(child, child->right, val);
        }
        return parent;
    }
};
