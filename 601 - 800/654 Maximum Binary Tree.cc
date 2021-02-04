// 60ms, 96.80%; 28.9MB, 45.32%
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
auto x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    TreeNode *constructMaximumBinaryTree(const vector<int> &nums)
    {
        if (nums.empty()) return nullptr;
        return build(nums, 0, nums.size());
    }

private:
    TreeNode *build(const vector<int> &nums, int i, int j)
    {
        int idx = distance(nums.begin(), max_element(nums.begin() + i, nums.begin() + j));
        TreeNode *node = new TreeNode(nums[idx]);
        if (i < idx) node->left = build(nums, i, idx);
        if (idx + 1 < j) node->right = build(nums, idx + 1, j);
        return node;
    }
};
