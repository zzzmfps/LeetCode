// 16ms, 91.39%; 21.9MB, 44.44%
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
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> res;
        vector<TreeNode *> st;
        st.push_back(root);
        while (!st.empty()) {
            res.push_back(0);
            vector<TreeNode *> tmp;
            for (auto *node : st) {
                res.back() += node->val;
                if (node->left) tmp.push_back(node->left);
                if (node->right) tmp.push_back(node->right);
            }
            res.back() /= st.size();
            st.swap(tmp);
        }
        return res;
    }
};
