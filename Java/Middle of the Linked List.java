// 0ms, 100.00%; 37MB, 7.84%
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public static ListNode middleNode(ListNode head) {
        ListNode fast = head;
        while (fast.next != null) {
            fast = fast.next;
            if (fast.next != null) {
                fast = fast.next;
            }
            head = head.next;
        }
        return head;
    }
}
