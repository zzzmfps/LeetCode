// 2ms, 72.69%
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;
        
        bool same = isSameTree(p->left, q->left);
        same *= isSameTree(p->right, q->right);
        if(p->val != q->val) same = false;
        
        return same;
    }
};
