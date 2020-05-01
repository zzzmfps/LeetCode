// 40ms, 86.49%; 8.6MB, 100.00%
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getIntersectionNode(headA, headB *ListNode) *ListNode {
	len1, len2 := length(headA), length(headB)
	if len1 < len2 {
		headB = advance(headB, len2-len1)
	} else {
		headA = advance(headA, len1-len2)
	}
	for headA != nil && headA != headB {
		headA = headA.Next
		headB = headB.Next
	}
	return headA
}

func length(head *ListNode) int {
	ret := 0
	for head != nil {
		ret++
		head = head.Next
	}
	return ret
}

func advance(head *ListNode, dist int) *ListNode {
	for i := dist; i > 0; i-- {
		head = head.Next
	}
	return head
}
