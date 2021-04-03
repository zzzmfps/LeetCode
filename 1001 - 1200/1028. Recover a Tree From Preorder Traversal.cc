// 20 ms, 70.66%; 20.1 MB, 53.32%
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
    TreeNode *recoverFromPreorder(const string &s) {
        size_t index = 0;
        return this->build(s, index, 0);
    }

private:
    TreeNode *build(const string &s, size_t &index, int height) {
        if (index == s.size()) return nullptr;

        size_t idx1 = s.find_first_not_of('-', index);
        int h = static_cast<int>(idx1 - index);
        if (h != height) return nullptr;

        size_t idx2 = std::min(s.size(), s.find_first_of('-', idx1));
        int v = std::stoi(s.substr(idx1, idx2 - idx1));
        index = idx2;

        TreeNode *node = new TreeNode(v);
        node->left = this->build(s, index, height + 1);
        if (node->left) node->right = this->build(s, index, height + 1);
        return node;
    }
};
