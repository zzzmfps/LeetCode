// 8ms, 98.45%
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode *> tmp;
        tmp.push(root);
        while (!tmp.empty()) {
            int size = tmp.size(), curMax = tmp.front()->val;
            for (int i = 0; i < size; ++i) {
                auto &x = tmp.front();
                tmp.pop();
                curMax = max(curMax, x->val);
                if (x->left) tmp.push(x->left);
                if (x->right) tmp.push(x->right);
            }
            res.push_back(curMax);
        }
        return res;
    }
};
