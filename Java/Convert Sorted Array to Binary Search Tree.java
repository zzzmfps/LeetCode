// 0ms, 100.00%; 39MB, 5.16%
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public static TreeNode sortedArrayToBST(int[] nums) {
        return build(nums, 0, nums.length - 1);
    }

    private static TreeNode build(int[] nums, int beg, int end) {
        if (beg > end) {
            return null;
        }
        int mid = beg + (end - beg + 1) / 2;
        TreeNode node = new TreeNode(nums[mid]);
        node.left = build(nums, beg, mid - 1);
        node.right = build(nums, mid + 1, end);
        return node;
    }
}
