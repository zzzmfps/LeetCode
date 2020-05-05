// 1ms, 97.67%; 41.8MB, 5.71%
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public static ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int lenA = length(headA), lenB = length(headB);
        if (lenA < lenB) {
            headB = advance(headB, lenB - lenA);
        } else {
            headA = advance(headA, lenA - lenB);
        }
        while (headA != null) {
            if (headA == headB) {
                return headA;
            }
            headA = headA.next;
            headB = headB.next;
        }
        return null;
    }

    private static int length(ListNode node) {
        int ret = 0;
        while (node != null) {
            ++ret;
            node = node.next;
        }
        return ret;
    }

    private static ListNode advance(ListNode node, int x) {
        while (x-- > 0) {
            node = node.next;
        }
        return node;
    }
}
