# 88ms, 67.64%; 16.5MB, 7.14%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        targets, st = set(), [root]
        while st:
            node = st.pop()
            if node.val in targets: return True
            targets.add(k - node.val)
            if node.left: st.append(node.left)
            if node.right: st.append(node.right)
        return False
