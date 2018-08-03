# 92ms, 82.79%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        if not inorder: return None
        root = TreeNode(postorder[-1])
        stack = [root]
        i, j = len(postorder) - 2, len(inorder) - 1
        while i >= 0:
            node = TreeNode(postorder[i])
            i, tmp = i - 1, None
            while stack and stack[-1].val == inorder[j]:
                tmp, j = stack.pop(), j - 1
            if tmp: tmp.left = node
            else: stack[-1].right = node
            stack.append(node)
        return root
    
