// 0ms, 100.00%; 39.2MB, 5.88%
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
    public boolean hasPathSum(TreeNode root, int sum) {
        return (null == root ? false : helper(root, sum));
    }

    private static boolean helper(TreeNode root, int sum) {
        int target = sum - root.val;
        if (root.left == root.right) {
            return 0 == target;
        }
        boolean flag1 = (null == root.left ? false : helper(root.left, target));
        boolean flag2 = (null == root.right ? false : helper(root.right, target));
        return flag1 || flag2;
    }
}
