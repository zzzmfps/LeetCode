// 22ms, 60.81%
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
    int pathSum(TreeNode *root, int sum) {
        if (!root) return 0;
        return find_path(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

private:
    int find_path(TreeNode *root, int sum) {
        if (!root) return 0;
        int dif = sum - root->val;
        return !dif + find_path(root->left, dif) + find_path(root->right, dif);
    }
};
