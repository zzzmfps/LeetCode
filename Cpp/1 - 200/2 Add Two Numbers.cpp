// 43ms, 72.98%
class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* l3 = new ListNode(0), *ans = l3;
        ListNode* zero = new ListNode(0);    // 'trap' node
        for(; l1 != l2; l3 = l3->next)
        {
            l3->val += l1->val + l2->val;
            l1 = l1->next ? l1->next : zero;
            l2 = l2->next ? l2->next : zero;
            if(l1 != l2)
                l3->next = new ListNode(l3->val > 9 ? 1 : 0);
            else if(l3->val > 9)
                l3->next = new ListNode(1);
            l3->val %= 10;
        }
        return ans;
    }
};
