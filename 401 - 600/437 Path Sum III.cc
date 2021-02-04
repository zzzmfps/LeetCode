// 22ms, 60.81%
class Solution {
public:
    int pathSum(TreeNode *root, int sum) {
        if (!root) return 0;
        return find_path(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

private:
    int find_path(TreeNode *root, int sum) {
        if (!root) return 0;
        int dif = sum - root->val;
        return !dif + find_path(root->left, dif) + find_path(root->right, dif);
    }
};
