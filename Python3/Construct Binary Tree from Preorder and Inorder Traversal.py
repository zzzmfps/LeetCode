# 88ms, 87.83%
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
            idx = val_to_index[nodeval]
            head = TreeNode(nodeval)
            head.left = build(preo, ino, pl + 1, pl + idx - il, il, idx - 1)
            head.right = build(preo, ino, pl + idx - il + 1, pr, idx + 1, ir)
            return head

        n = len(preorder)
        val_to_index = {val: idx for idx, val in enumerate(inorder)}
        return build(preorder, inorder, 0, n - 1, 0, n - 1)
