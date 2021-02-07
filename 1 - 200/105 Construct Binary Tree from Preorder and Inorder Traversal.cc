// 16ms, 53.60%
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
    typedef const vector<int> cvecint;

public:
    TreeNode *buildTree(cvecint &preorder, cvecint &inorder) {
        int n = preorder.size();
        return build(preorder, inorder, 0, n - 1, 0, n - 1);
    }

private:
    TreeNode *build(cvecint &preorder, cvecint &inorder, int pl, int pr, int il, int ir) {
        if (pl > pr) return nullptr;
        int nodeval = preorder[pl];
        TreeNode *head = new TreeNode(nodeval);
        if (pl < pr) {
            int idx = il;
            while (inorder[idx] != nodeval) ++idx;
            head->left = build(preorder, inorder, pl + 1, idx + pl - il, il, idx - 1);
            head->right = build(preorder, inorder, idx + pl - il + 1, pr, idx + 1, ir);
        }
        return head;
    }
};
