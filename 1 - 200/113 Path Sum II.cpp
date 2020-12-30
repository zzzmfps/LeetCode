// 9ms, 100.0%
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
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution
{
  private:
    vector<vector<int>> res;

  public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        if (root)
        {
            vector<int> combination;
            findPath(root, sum, combination);
        }
        return res;
    }

  private:
    void findPath(TreeNode *node, int target, vector<int> &com)
    {
        int cur_val = node->val;
        if (!node->left && !node->right)
        {
            if (cur_val == target)
            {
                res.push_back(com);
                res.back().push_back(cur_val);
            }
        }
        else
        {
            com.push_back(cur_val);
            if (node->left)
                findPath(node->left, target - cur_val, com);
            if (node->right)
                findPath(node->right, target - cur_val, com);
            com.pop_back();
        }
    }
};
