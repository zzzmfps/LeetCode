// 0ms, 100.00%; 2MB, 100.00%
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func middleNode(head *ListNode) *ListNode {
	var fast = head
	for fast.Next != nil {
		head = head.Next
		fast = fast.Next
		if fast.Next == nil {
			break
		}
		fast = fast.Next
	}
	return head
}
