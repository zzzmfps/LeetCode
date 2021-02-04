// 12ms, 4.36%
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *trav = head, *last = head;
        for(int i = 0; i < n; ++i)
            trav = trav->next;
        while(trav && trav->next)
        {
            trav = trav->next;
            last = last->next;
        }
        if(!trav && last == head) 
            head = last->next;
        else
            last->next = last->next->next;
        return head;
    }
};
