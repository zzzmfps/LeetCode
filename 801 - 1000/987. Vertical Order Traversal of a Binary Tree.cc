// 0 ms, 100.00%; 14 MB, 31.76%
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
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        vector<vector<int>> record;
        traverse(record, root, 0, 0);
        auto sortRule = [](const vector<int> &x, const vector<int> &y) {
            return x[2] < y[2] || x[2] == y[2] && x[1] < y[1] || x[2] == y[2] && x[1] == y[1] && x[0] < y[0];
        };
        sort(record.begin(), record.end(), sortRule);

        vector<vector<int>> res(1);
        for (int i = 0, lastCol = record[0][2]; i < record.size(); ++i) {
            if (record[i][2] != lastCol) {
                lastCol = record[i][2];
                res.push_back(vector<int>());
            }
            res.back().push_back(record[i][0]);
        }
        return res;
    }

private:
    void traverse(vector<vector<int>> &record, TreeNode *node, int row, int col) {
        record.push_back(vector<int>{node->val, row, col});
        if (node->left) traverse(record, node->left, row + 1, col - 1);
        if (node->right) traverse(record, node->right, row + 1, col + 1);
    }
};
