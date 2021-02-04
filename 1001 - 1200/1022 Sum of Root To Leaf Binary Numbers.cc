// 8ms, 100.00%; 17MB, 100.00%
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
    int sumRootToLeaf(TreeNode *root) { return helper(root, 0); }

private:
    int helper(TreeNode *root, int acc)
    {
        if (!root) return 0;
        acc = (acc << 1) | root->val;
        if (root->left == root->right) return acc;
        return helper(root->left, acc) + helper(root->right, acc);
    }
};
