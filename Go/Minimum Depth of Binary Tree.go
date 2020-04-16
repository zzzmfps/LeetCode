// 4ms, 97.27%; 5.1MB, 100.00%
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	cur, level := []*TreeNode{root}, 1
	for ; len(cur) > 0; level++ {
		tmp := make([]*TreeNode, 0, len(cur)<<1)
		for _, node := range cur {
			if node.Left == node.Right {
				return level
			}
			if node.Left != nil {
				tmp = append(tmp, node.Left)
			}
			if node.Right != nil {
				tmp = append(tmp, node.Right)
			}
		}
		cur = tmp
	}
	return -1 // unreachable
}
