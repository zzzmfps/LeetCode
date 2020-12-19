# 52ms, 87.32%; 15.7MB, 11.45%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        return self.__check(root, None, None)

    def __check(self, root: TreeNode, min_limit: int, max_limit: int) -> bool:
        if not root: return True
        if min_limit is not None and root.val <= min_limit: return False
        if max_limit is not None and root.val >= max_limit: return False
        return self.__check(root.left, min_limit, root.val) and self.__check(root.right, root.val, max_limit)
