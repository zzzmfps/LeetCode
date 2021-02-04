// 8ms, 46.47%
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if(!root) return 0;
        int count1 = minDepth(root->left);
        int count2 = minDepth(root->right);
        return 1 + (count1 * count2 ? min(count1, count2) : max(count1, count2));
    }
};
