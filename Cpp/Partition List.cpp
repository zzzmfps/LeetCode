// 8ms, 100.00%; 8.9MB, 5.41%
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        if (!head || !head->next) return head;
        
        ListNode *root = new ListNode(0);
        root->next = head;
        ListNode *ins = root;
        while (ins->next && ins->next->val < x) ins = ins->next;
        ListNode *pre = ins, *trav = ins->next;
        
        while (trav) {
            if (trav->val < x) {
                pre->next = trav->next;
                trav->next = ins->next;
                ins->next = trav;
                
                ins = ins->next;
                trav = pre->next;
            } else {
                pre = trav;
                trav = trav->next;
            }
        }
        return root->next;
    }
};
