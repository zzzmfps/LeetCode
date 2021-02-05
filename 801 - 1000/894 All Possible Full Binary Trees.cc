// 88 ms, 97.39%; 39.1 MB, 24.02%
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode *> allPossibleFBT(int N) {
        vector<TreeNode *> res;
        if (1 == N) {
            res.emplace_back(new TreeNode());
        } else if (N & 1) {
            for (int i = 2; i <= N; i += 2) {
                auto left = allPossibleFBT(i - 1);
                auto right = allPossibleFBT(N - i);
                for (int l = 0; l < left.size(); ++l) {
                    for (int r = 0; r < right.size(); ++r) {
                        res.emplace_back(new TreeNode());
                        res.back()->left = (r + 1 == right.size()) ? left[l] : copyTree(left[l]);
                        res.back()->right = (l + 1 == left.size()) ? right[r] : copyTree(right[r]);
                    }
                }
            }
        }
        return res;
    }

private:
    TreeNode *copyTree(TreeNode *root) const {
        TreeNode *newTree = new TreeNode();
        newTree->left = (root->left) ? copyTree(root->left) : nullptr;
        newTree->right = (root->right) ? copyTree(root->right) : nullptr;
        return newTree;
    }
};
