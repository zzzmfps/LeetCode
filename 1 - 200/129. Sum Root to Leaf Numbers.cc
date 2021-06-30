// 0 ms, 100.00%; 12.4MB, 87.32%
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
    int sumNumbers(TreeNode *root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode *root, int val) {
        if (!root) return 0;
        if (root->left == root->right) return val + root->val;
        val = 10 * (val + root->val);
        return dfs(root->left, val) + dfs(root->right, val);
    }
};
