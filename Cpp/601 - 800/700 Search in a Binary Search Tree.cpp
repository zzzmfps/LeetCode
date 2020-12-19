// 56ms, 42.91%; 28.9MB, 97.56%
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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        while (root) {
            if (root->val == val) break;
            root = (root->val > val ? root->left : root->right);
        }
        return root;
    }
};
