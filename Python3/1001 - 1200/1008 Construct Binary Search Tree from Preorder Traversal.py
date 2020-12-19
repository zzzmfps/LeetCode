# 40ms, 100.0%; 13.1MB, 100.0%
class Solution:
    def bstFromPreorder(self, preorder: list) -> TreeNode:
        head = TreeNode(preorder[0])
        for i in range(1, len(preorder)):
            self.__insert(head, preorder[i])
        return head

    def __insert(self, root: TreeNode, x: int) -> None:
        while True:
            if x < root.val:
                if root.left:
                    root = root.left
                else:
                    root.left = TreeNode(x)
                    return
            elif root.right:
                root = root.right
            else:
                root.right = TreeNode(x)
                return
