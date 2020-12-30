// 29ms, 25.02%
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if(!head) return nullptr;
        ListNode *trav = head;
        while(trav->val == val)
            if(!(trav = trav->next)) return nullptr;
        ListNode *next = trav->next;
        head = trav;
        
        while(next)
            if(next->val == val)
            {
                next = next->next;
                trav->next = next;
            }
            else
            {
                trav = next;
                next = next->next;
            }
        return head;
    }
};
