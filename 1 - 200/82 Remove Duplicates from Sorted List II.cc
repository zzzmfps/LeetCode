// 8ms, 91.67%; 9.4MB, 7.32%
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next) return head;
        ListNode *root = new ListNode(0);
        root->next = head;
        auto cur = root;
        while (cur->next) {
            auto nxt = cur->next;
            while (nxt->next && nxt->next->val == cur->next->val) nxt = nxt->next;
            if (cur->next == nxt) {
                cur = nxt;
            } else if (cur == root) {
                root->next = nxt->next;
            } else {
                cur->next = nxt->next;
            }
        }
        return root->next;
    }
};
