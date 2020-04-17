// 4ms, 97.23%; 4.8MB, 100.00%
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func hasPathSum(root *TreeNode, sum int) bool {
	return root != nil && dfs(root, sum)
}

func dfs(root *TreeNode, target int) bool {
	if root.Left == root.Right {
		return target == root.Val
	}
	if root.Left != nil && dfs(root.Left, target-root.Val) {
		return true
	}
	if root.Right != nil && dfs(root.Right, target-root.Val) {
		return true
	}
	return false
}
