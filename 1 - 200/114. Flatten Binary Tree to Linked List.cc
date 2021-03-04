// 8 ms, 62.21%; 12.6 MB, 78.98%
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
    void flatten(TreeNode *root) {
        if (!root) return;
        this->flatten(root->left);
        this->flatten(root->right);
        if (!root->right) swap(root->left, root->right);
        if (root->left) {
            auto it = root->left;
            while (it->right) it = it->right;
            it->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
    }
};
