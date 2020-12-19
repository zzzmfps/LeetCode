# 40ms, 58.73%; 13.2MB, 6.67%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flipEquiv(self, root1: TreeNode, root2: TreeNode) -> bool:
        if not root1 and not root2: return True
        if not root1 or not root2 or root1.val != root2.val: return False
        st1, st2 = [root1], [root2]
        while st1 and st2:
            node1, node2 = st1.pop(), st2.pop()
            x1, x2 = (node1.left.val if node1.left else 0), (node1.right.val if node1.right else 0)
            y1, y2 = (node2.left.val if node2.left else 0), (node2.right.val if node2.right else 0)
            if x1 == y1 and x2 == y2:
                if node1.left:
                    st1.append(node1.left)
                    st2.append(node2.left)
                if node1.right:
                    st1.append(node1.right)
                    st2.append(node2.right)
            elif x1 == y2 and x2 == y1:
                if node1.left:
                    st1.append(node1.left)
                    st2.append(node2.right)
                if node1.right:
                    st1.append(node1.right)
                    st2.append(node2.left)
            else:
                return False
        return not st1 and not st2
