// 35ms, 66.68%
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *tmp1 = headA, *tmp2 = headB;
        while(tmp1 != tmp2)
        {
            tmp1 = tmp1 ? tmp1->next : headB;
            tmp2 = tmp2 ? tmp2->next : headA;
        }
        return tmp1;
    }
};
