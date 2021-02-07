// 17ms, 85.06%
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution {
private:
    string res = "";

public:
    string tree2str(TreeNode *t) {
        if (!t) return "";
        helper(t);
        return res;
    }

private:
    void helper(TreeNode *t) {
        res += to_string(t->val);
        if (t->left || t->right) {
            res += "(";
            tree2str(t->left);
            res += ")";
            if (t->right) {
                res += "(";
                tree2str(t->right);
                res += ")";
            }
        }
    }
};
