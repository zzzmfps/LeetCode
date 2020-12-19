# 52ms, 50.91%; 13.3MB, 23.08%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minCameraCover(self, root: TreeNode) -> int:
        def dfs(root: TreeNode) -> int:
            if not root: return 2
            l, r = dfs(root.left), dfs(root.right)
            if l == 0 or r == 0:
                self.res += 1
                return 1
            # 0: leaf, 1: parent of a leaf and placed a camera, 2: covered by neighbour
            return 2 if l == 1 or r == 1 else 0

        self.res = 0
        return (dfs(root) == 0) + self.res
