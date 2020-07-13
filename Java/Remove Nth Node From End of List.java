// 0ms, 100.00%; 40MB, 5.06%
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public static ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode pre = head, post = head;
        for (int i = 0; i < n; ++i) {
            post = post.next;
        }
        if (post == null) {
            return head.next;
        }
        while (post.next != null) {
            pre = pre.next;
            post = post.next;
        }
        pre.next = pre.next.next;
        return head;
    }
}
