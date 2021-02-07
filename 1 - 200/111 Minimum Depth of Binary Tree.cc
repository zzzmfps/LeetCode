// 8ms, 46.47%
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
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        int count1 = minDepth(root->left);
        int count2 = minDepth(root->right);
        return 1 + (count1 * count2 ? min(count1, count2) : max(count1, count2));
    }
};
