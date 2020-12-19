# 376ms, 56.01%; 16.2MB, 100.00%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        ascending, st1, st2 = [], [], []
        head1, head2 = TreeNode(100001), TreeNode(100001)
        head1.left, head2.left = root1, root2
        self.__helper(st1, head1)
        self.__helper(st2, head2)
        while st1 and st2:
            st = (st1 if st1[-1].val < st2[-1].val else st2)
            ascending.append(st[-1].val)
            tmp = st.pop().right
            self.__helper(st, tmp)
        ascending.pop()
        return ascending

    def __helper(self, st: List[TreeNode], node: TreeNode) -> None:
        while node:
            st.append(node)
            node = node.left
