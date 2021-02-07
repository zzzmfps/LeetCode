// 4ms, 100.0%; 9MB, 100.0%
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
    TreeNode *bstFromPreorder(const vector<int> &preorder) {
        TreeNode *head = new TreeNode(preorder[0]);
        for (int i = 1, size = preorder.size(); i < size; ++i) insert(head, preorder[i]);
        return head;
    }

private:
    void insert(TreeNode *root, int val) {
        while (true) {
            if (val < root->val) {
                if (root->left) {
                    root = root->left;
                } else {
                    root->left = new TreeNode(val);
                    return;
                }
            } else if (root->right) {
                root = root->right;
            } else {
                root->right = new TreeNode(val);
                return;
            }
        }
    }
};
