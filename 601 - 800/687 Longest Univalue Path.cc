// 67ms, 66.89%
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
private:
    int length;

public:
    int longestUnivaluePath(TreeNode *root) {
        traverse(root);
        return length;
    }

private:
    int traverse(TreeNode *node) {
        if (!node) return 0;
        int left_len = traverse(node->left);
        int right_len = traverse(node->right);
        int left = node->left && node->left->val == node->val ? left_len + 1 : 0;
        int right = node->right && node->right->val == node->val ? right_len + 1 : 0;
        length = max(length, left + right);
        return max(left, right);
    }
};
