# 28ms, 97.38%; 13MB, 100.00%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> list:
        res, q = [], []
        if root: q.append(root)
        while q:
            res.append([])
            new_q = []
            for node in q:
                res[-1].append(node.val)
                if node.left: new_q.append(node.left)
                if node.right: new_q.append(node.right)
            q = new_q
        return res
    
