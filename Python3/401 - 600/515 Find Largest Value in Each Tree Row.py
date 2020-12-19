# 56ms, 99.44%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root: return []
        res, level = [], []
        level.append(root)
        while level:
            lens, cur_max, tmp = len(level), level[0].val, []
            for i in range(lens):
                x = level[i]
                cur_max = max(cur_max, x.val)
                if x.left: tmp.append(x.left)
                if x.right: tmp.append(x.right)
            res.append(cur_max)
            level = tmp
        return res
    
