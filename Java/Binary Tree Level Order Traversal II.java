// 1ms, 81.43%; 39.8MB, 5.00%
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
    public static List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> res = new LinkedList<>();
        List<TreeNode> cur = new LinkedList<>();
        if (root != null) {
            cur.add(root);
        }
        while (!cur.isEmpty()) {
            res.add(0, new LinkedList<>());
            List<TreeNode> next = new LinkedList<>();
            for (TreeNode node : cur) {
                res.get(0).add(node.val);
                if (node.left != null) {
                    next.add(node.left);
                }
                if (node.right != null) {
                    next.add(node.right);
                }
            }
            cur = next;
        }
        return res;
    }
}
