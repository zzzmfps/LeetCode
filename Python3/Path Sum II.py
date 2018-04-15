# 52ms, 100.0%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.res = []
        self.com = []

    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """

        def helper(node, target):
            cur_val = node.val
            if not node.left and not node.right:
                if cur_val == target:
                    self.res.append(self.com[:])
                    self.res[-1].append(target)
            else:
                self.com.append(cur_val)
                if node.left:
                    helper(node.left, target - cur_val)
                if node.right:
                    helper(node.right, target - cur_val)
                self.com.pop()

        if root:
            helper(root, sum)
        return self.res
        
