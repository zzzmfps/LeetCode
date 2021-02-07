// 16ms, 100.0%; 18.5MB, 100.0%
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
private:
    int res = 0;

public:
    int minCameraCover(TreeNode *root) {
        return (dfs(root) == 0) + res;
    }

private:
    int dfs(TreeNode *root) {
        if (!root) return 2;
        int l = dfs(root->left), r = dfs(root->right);
        if (l == 0 || r == 0) {
            res += 1;
            return 1;
        }
        return (l == 1 || r == 1) ? 2 : 0;
    }
};
