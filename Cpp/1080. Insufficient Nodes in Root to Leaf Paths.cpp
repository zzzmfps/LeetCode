// 32ms, 99.89%; 23.5MB, 100.00%
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
    TreeNode *sufficientSubset(TreeNode *root, int limit)
    {
        TreeNode tmp(0);
        tmp.left = root;
        helper(&tmp, limit, 0);
        return tmp.left;
    }

private:
    bool helper(TreeNode *node, int limit, int val)
    {
        if (!node) return false;
        val += node->val;
        if (node->left || node->right) {
            bool flag1 = helper(node->left, limit, val);
            bool flag2 = helper(node->right, limit, val);
            if (!flag1) node->left = nullptr;
            if (!flag2) node->right = nullptr;
            return flag1 || flag2;
        }
        return limit <= val;
    }
};
