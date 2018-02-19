// 14ms, 23.04%
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *del = node->next;
        node->val = del->val;
        node->next = del->next;
        delete del;
    }
};
