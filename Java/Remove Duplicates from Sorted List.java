// 1ms, 9.60%; 41.1MB, 7.14%
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode tmp = head;
        while (tmp != null) {
            ListNode _next = tmp.next;
            while (_next != null && _next.val == tmp.val) {
                _next = _next.next;
            }
            tmp.next = _next;
            tmp = _next;
        }
        return head;
    }
}
