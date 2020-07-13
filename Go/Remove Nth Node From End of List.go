// 4ms, 17.45%; 2.4MB, 5.06%
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	pre, post := head, head
	for i := 0; i < n; i++ {
		post = post.Next
	}
	if post == nil {
		return head.Next
	}
	for post.Next != nil {
		pre, post = pre.Next, post.Next
	}
	pre.Next = pre.Next.Next
	return head
}
