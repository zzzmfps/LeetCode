// 4ms, 90.22%; 4.4MB, 100.00%
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	queue := []*TreeNode{root}
	res := 0
	for ; len(queue) != 0; res++ {
		tmp := make([]*TreeNode, 0, len(queue)<<1)
		for _, node := range queue {
			if node.Left != nil {
				tmp = append(tmp, node.Left)
			}
			if node.Right != nil {
				tmp = append(tmp, node.Right)
			}
		}
		queue = tmp
	}
	return res
}

