# runtime: bfs (iteration) EQUALs to dfs (recursion) in python


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


# 0, bfs: 36ms, 87.85%; 13.1MB, 5.36%
class Solution:
    def isUnivalTree(self, root: TreeNode) -> bool:
        val = root.val
        st = [root]
        while st:
            rep = []
            for elem in st:
                if elem.val != val: return False
                if elem.left: rep.append(elem.left)
                if elem.right: rep.append(elem.right)
            st = rep
        return True
        
        
# 1, dfs: 36ms, 87.85%; 12.9MB, 5.36%
class Solution:
    def isUnivalTree(self, root: TreeNode) -> bool:
        if root.left:
            if root.left.val != root.val: return False
            if not self.isUnivalTree(root.left): return False
        if root.right:
            if root.right.val != root.val: return False
            if not self.isUnivalTree(root.right): return False
        return True
    
