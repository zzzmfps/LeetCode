// 16ms, 19.75%
class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if(!nums.size()) return nullptr;
        TreeNode *root = helper(nums, 0, nums.size() - 1);
        return root;
    }
    
    TreeNode *helper(vector<int> &nums, int begin, int end)
    {
        if(begin > end) return nullptr;
        int mid = (begin + end + 1) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(nums, begin, mid - 1);
        root->right = helper(nums, mid + 1, end);
        return root;
    }
};
