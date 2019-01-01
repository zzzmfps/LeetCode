# 472ms, 9.77%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """

        def build(preo, ino, pl, pr, il, ir):
            if pl > pr: return None
            nodeval = preo[pl]
            head = TreeNode(nodeval)
            if pl < pr:
                idx = il
                while ino[idx] != nodeval:
                    idx += 1
                head.left = build(preo, ino, pl + 1, pl + idx - il, il, idx - 1)
                head.right = build(preo, ino, pl + idx - il + 1, pr, idx + 1, ir)
            return head

        n = len(preorder)
        return build(preorder, inorder, 0, n - 1, 0, n - 1)
