// 176 ms, 35.73%; 86.5 MB, 59.85%
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
    int goodNodes(TreeNode *root) {
        return dfs(root, INT_MIN);
    }

private:
    int dfs(TreeNode *node, int limit) {
        if (!node) return 0;
        limit = max(limit, node->val);
        int good = node->val == limit ? 1 : 0;
        return good + dfs(node->left, limit) + dfs(node->right, limit);
    }
};
