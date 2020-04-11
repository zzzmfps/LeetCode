// 4ms, 86.97%; 3.1MB, 100.00%
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
	cur := head
	for cur != nil {
		cur.Next = nextDifferent(cur, cur.Val)
		cur = cur.Next
	}
	return head
}

func nextDifferent(head *ListNode, val int) *ListNode {
	node := head
	for node != nil && node.Val == val {
		node = node.Next
	}
	return node
}
