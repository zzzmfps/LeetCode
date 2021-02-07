// 52ms, 52.98%; 32.1MB, 100.00%
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
    int deepestLeavesSum(TreeNode *root) {
        int _sum = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            _sum = 0;
            for (int i = q.size(); i > 0; --i) {
                auto tmp = q.front();
                q.pop();
                _sum += tmp->val;
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
        }
        return _sum;
    }
};
