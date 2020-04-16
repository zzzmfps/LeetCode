// 0ms, 100.00%; 2.8MB, 100.00%
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrderBottom(root *TreeNode) [][]int {
	res, cur := [][]int{}, []*TreeNode{}
	if root != nil {
		cur = append(cur, root)
	}
	for len(cur) > 0 {
		tmp := make([]int, 0, len(cur))
		next := make([]*TreeNode, 0, len(cur)<<1)
		for _, node := range cur {
			tmp = append(tmp, node.Val)
			if node.Left != nil {
				next = append(next, node.Left)
			}
			if node.Right != nil {
				next = append(next, node.Right)
			}
		}
		res = append(res, tmp)
		cur = next
	}
	return reverse(res)
}

func reverse(matrix [][]int) [][]int {
	i, j := 0, len(matrix)-1
	for i < j {
		matrix[i], matrix[j] = matrix[j], matrix[i]
		i, j = i+1, j-1
	}
	return matrix
}
