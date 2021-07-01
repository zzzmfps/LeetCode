// 20 ms, 32.34%; 21 MB, 5.04%
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        map<TreeNode *, pair<TreeNode *, size_t>> cache;
        auto visit = [&](auto &&self, TreeNode *node, TreeNode *prev, size_t level) {
            static bool p_ = false, q_ = false;
            if (!node || (p_ && q_)) return;
            p_ = (node == p), q_ = (node == q);
            cache[node] = make_pair(prev, level);
            self(self, node->left, node, 1 + level);
            self(self, node->right, node, 1 + level);
        };
        visit(visit, root, root, 0);

        while (true) {
            auto &p_ = cache[p], &q_ = cache[q];
            if (p_.first == q_.first) break;
            auto &deep = (p_.second > q_.second ? p : q);
            deep = cache[deep].first;
        }
        return (p == q ? p : cache[p].first);
    }
};
