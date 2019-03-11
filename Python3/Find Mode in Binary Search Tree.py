# 64ms, 86.91%; 17.5MB, 6.67%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findMode(self, root: TreeNode) -> list:
        def preorder(root: TreeNode) -> None:
            if not root: return
            if root.val in rec:
                rec[root.val] += 1
            else:
                rec[root.val] = 1
            preorder(root.left)
            preorder(root.right)

        if not root: return []
        rec = dict()
        preorder(root)
        max_cnt = max(rec.values())
        return [x for x in rec if rec[x] == max_cnt]
