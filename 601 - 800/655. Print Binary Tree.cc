// 4 ms, 54.67%; 8.4 MB, 76.33%
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<string>> printTree(TreeNode *root) {
        int height = this->getHeight(root);
        int places = static_cast<int>(pow(2, height)) - 1;

        vector<vector<string>> res(height, vector<string>(places, ""));
        this->build(root, res, 0, 0, places);
        return res;
    }

private:
    int getHeight(TreeNode *node) {
        if (!node) return 0;
        if (node->left == node->right) return 1;
        int lh = this->getHeight(node->left);
        int rh = this->getHeight(node->right);
        return 1 + max(lh, rh);
    }

    void build(TreeNode *node, vector<vector<string>> &res, int level, int l, int r) {
        if (!node) return;
        int mid = l + (r - l) / 2;
        res[level][mid] = to_string(node->val);
        this->build(node->left, res, level + 1, l, mid);
        this->build(node->right, res, level + 1, mid + 1, r);
    }
};
