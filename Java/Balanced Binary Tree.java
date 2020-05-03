// 0ms, 100.00%; 39.5MB, 73.15%
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public static boolean isBalanced(TreeNode root) {
        return helper(root) > -1;
    }

    private static int helper(TreeNode node) {
        if (node == null) {
            return 0;
        }
        int lheight = helper(node.left), rheight = helper(node.right);
        if (lheight < 0 || rheight < 0 || Math.abs(lheight - rheight) > 1) {
            return -1;
        }
        return 1 + Math.max(lheight, rheight);
    }
}
