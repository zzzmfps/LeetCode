// 2ms, 24.69%; 39.1MB, 36.73%
import java.util.Vector;

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
    public static boolean isSymmetric(TreeNode root) {
        Vector<TreeNode> vec = new Vector<>(vec.size() << 1);
        vec.addElement(root);
        while (!vec.isEmpty()) {
            Vector<TreeNode> tmp = new Vector<>();
            vec.forEach(node -> {
                if (node != null) {
                    tmp.addElement(node.left);
                    tmp.addElement(node.right);
                }
            });
            int i = 0, j = tmp.size() - 1;
            while (i < j) {
                TreeNode n1 = tmp.elementAt(i++);
                TreeNode n2 = tmp.elementAt(j--);
                if (n1 != n2 && (n1 == null || n2 == null || n1.val != n2.val)) {
                    return false;
                }
            }
            vec = tmp;
        }
        return true;
    }
}
