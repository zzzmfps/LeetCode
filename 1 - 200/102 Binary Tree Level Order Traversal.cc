// 8ms, 57.76%; 13.8MB, 98.59%
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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        if (root) q.push(root);
        while (!q.empty()) {
            res.push_back(vector<int>());
            for (int i = q.size(); i > 0; --i) {
                auto tmp = q.front();
                q.pop();
                res.back().push_back(tmp->val);
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
        }
        return res;
    }
};
