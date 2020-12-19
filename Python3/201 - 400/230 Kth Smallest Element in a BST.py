# 52ms, 59.95%; 16.6MB, 98.18%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        st, flag = [root], True
        while True:
            if flag and st[-1].left:
                st.append(st[-1].left)
            else:
                if k == 1: break
                k, flag, tmp = k - 1, False, st.pop()
                if tmp.right:
                    st.append(tmp.right)
                    flag = True
        return st[-1].val
