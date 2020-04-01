// 4ms, 99.44%; 4.7MB, 40.00%
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeElements(head *ListNode, val int) *ListNode {
	root := &ListNode{0, head}
	for cur := root; cur != nil && cur.Next != nil; {
		if cur.Next.Val == val {
			cur.Next = cur.Next.Next
        } else {
            cur = cur.Next
        }
	}
	return root.Next
}
