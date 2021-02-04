// 39ms, 89.14%
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
    int val = 0;

  public:
    TreeNode *convertBST(TreeNode *root)
    {
        visit(root);
        return root;
    }

  private:
    void visit(TreeNode *node)
    {
        if (node)
        {
            visit(node->right);
            node->val += val;
            val = node->val;
            visit(node->left);
        }
    }
};
