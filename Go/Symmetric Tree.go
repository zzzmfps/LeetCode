// 0ms, 100.00%; 2.9MB, 25.00%
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSymmetric(root *TreeNode) bool {
	vec := []*TreeNode{root}
	for len(vec) > 0 {
		i, j := 0, len(vec)-1
		for i < j {
			if vec[i] != vec[j] && (vec[i] == nil || vec[j] == nil || vec[i].Val != vec[j].Val) {
				return false
			}
			i, j = i+1, j-1
		}
		tmp := make([]*TreeNode, 0, len(vec)<<1)
		for _, node := range vec {
			if node != nil {
				tmp = append(tmp, node.Left, node.Right)
			}
		}
		vec = tmp
	}
	return true
}
