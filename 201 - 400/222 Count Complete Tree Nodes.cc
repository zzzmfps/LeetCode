// 12ms, 100.0%
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
    int countNodes(TreeNode *root) {
        if (!root) return 0;
        stack<TreeNode *> tmp;
        tmp.push(root);
        int ret = 0;
        while (!tmp.empty()) {
            auto x = tmp.top();
            tmp.pop();
            ++ret;
            if (x->left) {
                tmp.push(x->left);
                if (x->right) tmp.push(x->right);
            }
        }
        return ret;
    }
};
