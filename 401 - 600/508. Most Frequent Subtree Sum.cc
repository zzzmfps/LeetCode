// 12 ms, 98.56%; 24.8 MB, 69.92%
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
    vector<int> findFrequentTreeSum(TreeNode *root) {
        unordered_map<int, int> counts;
        // 40 ms, 13.00%; 24.7 MB, 77.74%
        // Using lambda in recursion is much slower than member function.
        //
        // auto dfs = [&counts](auto &&self, TreeNode *node) -> int {
        //     if (!node) return 0;
        //     if (node->left == node->right) {
        //         ++counts[node->val];
        //         return node->val;
        //     }
        //     int lval = self(self, node->left), rval = self(self, node->right);
        //     int subtree = node->val + lval + rval;
        //     ++counts[subtree];
        //     return subtree;
        // };
        // dfs(dfs, root);
        dfs(counts, root);

        vector<int> res;
        int freq = 0;
        for (auto &&p : counts) {
            if (p.second > freq) freq = p.second, res.clear();
            if (p.second == freq) res.push_back(p.first);
        }
        return res;
    }

private:
    int dfs(unordered_map<int, int> &counts, TreeNode *node) {
        if (!node) return 0;
        if (node->left == node->right) {
            ++counts[node->val];
            return node->val;
        }
        int lval = dfs(counts, node->left), rval = dfs(counts, node->right);
        int subtree = node->val + lval + rval;
        ++counts[subtree];
        return subtree;
    }
};
