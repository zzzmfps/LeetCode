// 24ms, 96.53%; 24.6MB, 72.73%
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
private:
    int _max = INT_MIN;

public:
    int maxPathSum(TreeNode *root)
    {
        helper(root);
        return _max;
    }

    int helper(TreeNode *root)
    { // update `_max`, `root->val` itself is always included
        if (!root) return 0;
        int left = helper(root->left), right = helper(root->right);
        int _sum = root->val + max(0, left) + max(0, right);
        _max = max(_max, _sum);
        return root->val + max({0, left, right});
    }
};

