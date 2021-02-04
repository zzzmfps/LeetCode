// 13ms, 18.25%
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        
        ListNode *temp = nullptr;
        if(l1->val > l2->val)
        {
            temp = l1;
            l1 = l2;
            l2 = temp;
        }
        ListNode *merged = l1;
        
        while(l2)
            if(l1->next == nullptr)
            {
                l1->next = l2;
                break;
            }
            else if(l1->next->val <= l2->val)
                l1 = l1->next;
            else
            {
                temp = l2;
                l2 = l2->next;
                temp->next = l1->next;
                l1->next = temp;
                l1 = l1->next;
            }
        return merged;
    }
};
