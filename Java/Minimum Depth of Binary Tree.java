// 0ms, 100.00%; 39.6MB, 90.63%
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
    public static int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        Deque<TreeNode> dq = new LinkedList<>();
        dq.offer(root);
        for (int i = 1;; ++i) {
            for (int j = dq.size(); j > 0; --j) {
                TreeNode node = dq.poll();
                if (node.left == node.right) {
                    return i;
                }
                if (node.left != null) {
                    dq.offer(node.left);
                }
                if (node.right != null) {
                    dq.offer(node.right);
                }
            }
        }
    }
}
