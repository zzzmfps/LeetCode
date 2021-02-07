// 56ms, 100.0%; 25.3MB, 100.0%
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
private:
    TreeNode *head, *track;

public:
    Solution() {
        head = new TreeNode(0);
        track = head;
    }

    TreeNode *increasingBST(TreeNode *root) {
        if (!root) return nullptr;
        increasingBST(root->left);
        track->right = new TreeNode(root->val);
        track = track->right;
        increasingBST(root->right);
        return head->right;
    }
};
