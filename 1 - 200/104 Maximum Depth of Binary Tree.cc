// 12ms, 0.82%
class Solution
{
public:
    int maxDepth(TreeNode* root)
    {
        if(!root) return 0;
        int count1 = maxDepth(root->left) + 1;
        int count2 = maxDepth(root->right) + 1;
        return count1 > count2 ? count1 : count2;
    }
};
