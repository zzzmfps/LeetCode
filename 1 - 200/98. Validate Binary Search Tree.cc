// 16ms, 99.87%; 20.7MB, 27.46%
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
    bool isValidBST(TreeNode *root) {
        return check(root);
    }

private:
    bool check(TreeNode *root, long long minLimit = LONG_LONG_MIN, long long maxLimit = LONG_LONG_MAX) {
        if (!root) return true;
        if (root->val <= minLimit || root->val >= maxLimit) return false;
        return check(root->left, minLimit, root->val) && check(root->right, root->val, maxLimit);
    }
};
