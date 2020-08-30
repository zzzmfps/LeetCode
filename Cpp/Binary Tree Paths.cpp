// 7ms, 14.77%
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> res;
        if(root) helper(root, res, to_string(root->val));
        return res;
    }

private:
    void helper(TreeNode *root, vector<string> &res, string t) {
        if(!root->left && !root->right) {
            res.push_back(t);
        }
        else {
            if(root->left) helper(root->left, res, t + "->" + to_string(root->left->val));
            if(root->right) helper(root->right, res, t + "->" + to_string(root->right->val));
        }
    }
};
