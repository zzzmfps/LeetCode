# 44ms, 25.35%; 13.8MB, 14.29%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def insertIntoMaxTree(self, root: TreeNode, val: int) -> TreeNode:
        if not root: return TreeNode(val)
        if root.val < val:
            node = TreeNode(val)
            node.left = root
            return node
        return self.insert(root, root.right, val)

    def insert(self, parent: TreeNode, child: TreeNode, val: int) -> TreeNode:
        if not child:
            parent.right = TreeNode(val)
        elif child.val < val:
            parent.right = TreeNode(val)
            parent.right.left = child
        else: 
            self.insert(child, child.right, val)
        return parent
