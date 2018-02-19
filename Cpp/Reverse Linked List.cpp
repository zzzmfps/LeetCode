// 9ms, 13.51%
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if(!head) return head;
        ListNode *pre = head, *nxt = pre->next, *tmp = pre;
        while(nxt)
        {
            head = nxt;
            pre->next = nxt->next;
            nxt->next = tmp;
            nxt = pre->next;
            tmp = head;
        }
        return head;
    }
};
