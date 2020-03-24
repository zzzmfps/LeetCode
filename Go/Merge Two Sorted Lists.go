// 0ms, 100.00%; 2.5MB, 71.43%
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    if l1 == nil {
        return l2
    } else if l2 == nil {
        return l1
    }
	if l1.Val > l2.Val {
		l1, l2 = l2, l1
	}
	root := l1
	for l1.Next != nil && l2 != nil {
		next := l1.Next
		if next.Val <= l2.Val {
			l1 = next
		} else {
			end := l2
			for end.Next != nil && end.Next.Val <= next.Val {
				end = end.Next
			}
			l1.Next, l2, end.Next, l1 = l2, end.Next, next, next
		}
	}
	if l2 != nil {
		l1.Next = l2
	}
	return root
}
