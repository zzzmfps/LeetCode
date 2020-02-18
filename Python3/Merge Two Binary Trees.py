# 92ms, 51.10%; 13.8MB, 74.29%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        if t1 is t2: return None
        if t1 is None or t2 is None: return t1 if t1 else t2
        t1.val += t2.val
        st1, st2 = [t1], [t2]
        while st1:
            node1, node2 = st1.pop(), st2.pop()
            node1.left = self.__helper(node1.left, node2.left, st1, st2)
            node1.right = self.__helper(node1.right, node2.right, st1, st2)
        return t1

    def __helper(self, t1: TreeNode, t2: TreeNode, st1: list, st2: list) -> TreeNode:
        if t1 and t2:
            t1.val += t2.val
            st1.append(t1)
            st2.append(t2)
        elif t2:
            return t2
        return t1
        
