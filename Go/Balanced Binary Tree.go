// 4ms, 98.77%; 5.7MB, 100.00%
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isBalanced(root *TreeNode) bool {
	return helper(root) >= 0
}

func helper(node *TreeNode) int {
	if node == nil {
		return 0
	}
	lHeight, rHeight := helper(node.Left), helper(node.Right)
	if lHeight < 0 || rHeight < 0 || abs(lHeight-rHeight) > 1 {
		return -1
	}
	return 1 + max(lHeight, rHeight)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
