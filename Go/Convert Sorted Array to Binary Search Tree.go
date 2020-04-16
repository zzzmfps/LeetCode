// 108ms, 66.67%; 152.4MB, 100.00%
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sortedArrayToBST(nums []int) *TreeNode {
	return build(nums, 0, len(nums)-1)
}

func build(nums []int, beg, end int) *TreeNode {
	if beg > end {
		return nil
	}
	mid := beg + (end-beg+1)/2
	node := &TreeNode{Val: nums[mid]}
	node.Left = build(nums, beg, mid-1)
	node.Right = build(nums, mid+1, end)
	return node
}
