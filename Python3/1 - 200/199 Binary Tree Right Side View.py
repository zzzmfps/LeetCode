# 40ms, 50.62%; 12.8MB, 100.00%
class Solution:
    def rightSideView(self, root: TreeNode) -> list:
        res = []
        self.__helper(root, 1, res)
        return res

    def __helper(self, root: TreeNode, level: int, res: list):
        if not root: return
        if level > len(res): res.append(root.val)
        self.__helper(root.right, level + 1, res)
        self.__helper(root.left, level + 1, res)
