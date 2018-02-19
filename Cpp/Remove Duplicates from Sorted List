// 11ms, 55.59%
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if(!head) return head;
        
        ListNode *left = head;
        ListNode *right = head->next;
        while(right != nullptr)
        {
            if(left->val != right->val)
            {
                left->next = right;
                left = right;
            }
            right = right->next;
        }
        left->next = nullptr;
        return head;
    }
};
