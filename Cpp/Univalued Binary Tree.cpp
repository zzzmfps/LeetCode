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
 
 
 // 4ms, 100.00%; 10.7MB, 99.47%
class Solution
{
public:
    bool isUnivalTree(TreeNode *root)
    {
        int val = root->val;
        deque<TreeNode *> dq;
        dq.push_back(root);
        while (!dq.empty()) {
            for (int i = dq.size(); i > 0; --i) {
                TreeNode *tmp = dq.front();
                if (tmp->val != val) return false;
                dq.pop_front();
                if (tmp->left) dq.push_back(tmp->left);
                if (tmp->right) dq.push_back(tmp->right);
            }
        }
        return true;
    }
};

// 4ms, 100.00%; 10.8MB, 99.47%
class Solution
{
public:
    bool isUnivalTree(TreeNode *root)
    {
        if (root->left) {
            if (root->left->val != root->val) return false;
            if (!isUnivalTree(root->left)) return false;
        }
        if (root->right) {
            if (root->right->val != root->val) return false;
            if (!isUnivalTree(root->right)) return false;
        }
        return true;
    }
};
