// 4ms, 97.12%; 15.4MB, 18.18%
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
    int maxAncestorDiff(TreeNode *root) {
        int ret = 0;
        helper(root, ret);
        return ret;
    }

private:
    pair<int, int> helper(TreeNode *node, int &ret) {
        if (node->left == node->right) return make_pair(node->val, node->val);
        int _max = 0, _min = 100000;
        if (node->left) {
            auto p1 = helper(node->left, ret);
            _max = max(p1.first, p1.second);
            _min = min(p1.first, p1.second);
        }
        if (node->right) {
            auto p2 = helper(node->right, ret);
            _max = max({_max, p2.first, p2.second});
            _min = min({_min, p2.first, p2.second});
        }
        ret = max({ret, abs(node->val - _max), abs(node->val - _min)});
        return make_pair(min(node->val, _min), max(node->val, _max));
    }
};
