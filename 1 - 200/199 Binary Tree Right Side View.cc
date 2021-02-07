// 4ms, 73.36%; 9.6MB, 75.68%
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        helper(root, 1, res);
        return res;
    }

private:
    void helper(TreeNode *root, int level, vector<int> &res) {
        if (!root) return;
        if (level > res.size()) res.push_back(root->val);
        helper(root->right, level + 1, res);
        helper(root->left, level + 1, res);
    }
};
