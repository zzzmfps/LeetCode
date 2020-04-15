// 1ms, 12.68%; 39.8MB, 69.89%
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
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        Deque<TreeNode> q = new LinkedList<>();
        q.offer(root);
        int res;
        for (res = 0; !q.isEmpty(); ++res) {
            for (int i = q.size(); i > 0; --i) {
                TreeNode node = q.poll();
                if (node.left != null) {
                    q.offer(node.left);
                }
                if (node.right != null) {
                    q.offer(node.right);
                }
            }
        }
        return res;
    }
}
