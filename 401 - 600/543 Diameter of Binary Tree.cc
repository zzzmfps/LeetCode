// 4ms, 100.0%
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        int ret = 0;
        depthOfBinaryTree(root, ret);
        return ret;
    }

private:
    int depthOfBinaryTree(TreeNode *root, int &ret) {
        if (!root) return 0;
        int left = depthOfBinaryTree(root->left, ret);
        int right = depthOfBinaryTree(root->right, ret);
        ret = max(ret, left + right);
        return 1 + max(left, right);
    }
};
